/*
 ** Mini unit testing framework based on
 ** http://www.jera.com/techinfo/jtns/jtn002.html
 ** and extended by @ayellin
*/
#include "minunit.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
/* for ETIMEDOUT */
#include <errno.h>


int g_tests_failed = 0;
int g_tests_run = 0;

char*	make_full_msg(const char* msg, const char* fname, const char* sep) {
    char* full_msg;
    
    full_msg = (char*)malloc(BUF_SIZE);
    sprintf(full_msg, "%s %s %s",  fname, sep, msg);
    return full_msg;
}

static void print_error(char* msg) {
    printf("%sERROR: %s\n", KRED, msg);
    //free(msg);
}

void print_results() {
    if (g_tests_failed == 0)
   	{
        printf("%sALL %d TESTS PASSED\n", KGRN, g_tests_run);
		return ;
	}	
	printf("%s~~~~RESULTS~~~~\n", KMAG);
    printf("%sTESTS_FAILED: %d\n",KRED, g_tests_failed);
    printf("%sTESTS_PASSED: %d\n", KGRN, g_tests_run - g_tests_failed);
    printf("%sTESTS_RUN: %d\n", KCYN, g_tests_run);
}

void test_all(const char *test_suite, int n, ...) {
    printf("%s~~~~TESTING_SUITE[%s] ~~~~\n", KMAG, test_suite);
    va_list funcs;
    va_start(funcs, n);
    for (int i = 0; i < n; i++) {
        mu_run_test(va_arg(funcs, test_func_ptr_t));
    }
    print_results();
}

char* make_str_msg(char* msg, const char* s1, const char* s2, const char* fname) {
    char *full_msg;

    full_msg = (char *)malloc(BUF_SIZE);
    if (!full_msg)
        return (NULL);
    sprintf(full_msg, "%s -> %s: %s != %s", fname, msg, s1, s2);
    return (full_msg);
}

char* make_int_msg(char* message, int  i1, int i2, const char* fname){
    char* msg = malloc(BUF_SIZE);
    sprintf (msg, "%s -> %s: %d != %d", fname, message, i1, i2);
    return msg;
}

char* make_flt_msg(char* message, double f1, double f2, const char* fname) {
    char* msg = malloc(BUF_SIZE);
    sprintf (msg, "%s -> %s: %.2f != %.2f", fname, message, f1, f2);
    return msg;
}

char* make_ui_msg(char* message, unsigned f1, unsigned f2, const char* fname) {
    char* msg = malloc(BUF_SIZE);
    sprintf (msg, "%s -> %s: %u != %u", fname, message, f1, f2);
    return msg;
}

char *make_mem_msg(char *message, const void *m1, const void *m2, size_t n, const char *fname)
{
    char* msg = malloc(BUF_SIZE);
    char s1[n + 1];
    char s2[n + 1];
    memcpy(s1, m1, n);
    memcpy(s2, m2, n);
    s1[n] = '\0';
    s2[n] = '\0';
    sprintf (msg, "%s -> %s: [%s] != [%s]", fname, message, s1, s2);
    return msg;
}

char	*test_program_return(const char *prog_name, int expected_ret)
{
	int		real_ret;

	real_ret = system(prog_name);
	mu_assert_i("must be another value: [expected] != [real]", expected_ret, real_ret);
	return (0);
}

int 	open_new_file(const char *file_name)
{
	return (open(file_name, O_WRONLY | O_CREAT, 0777));
}

int		close_remove_file(const int fd, const char *file_name)
{
	if (fd != -1)
		close(fd);
	return (remove(file_name) == 0);
}

int 	is_file_empty(const char *file_name)
{
	ssize_t size;
	int fd;
	char buf[BUF_SIZE];

	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (-1);
	size = read(fd, buf, BUF_SIZE);
	return (size == 0);
}

int 	create_new_file(const char *file_name)
{
	int fd;

	remove(file_name);
	if ((fd = open_new_file(file_name))< 0)
		return (-1);
	return (close(fd));
}

static int g_file_i = 0;

void generate_unique_name(char *name, const char *filename, const char *prefix)
{
	sprintf(name, "%s%d.%s", filename, g_file_i, prefix);
}

char 	*assert_files(const char *file1, const char *file2)
{
	char diff_file[BUF_SIZE];
	char cmd_buff[BUF_SIZE];
	static char *error_msg;

	cmd_buff[0] = '\0';
	error_msg = "Files not equal. See mu_test.diff";
	generate_unique_name(diff_file, "mu_test", "diff");
	g_file_i++;
	create_new_file(diff_file);
	sprintf(cmd_buff, "diff %s %s > %s", file1, file2, diff_file);
	system(cmd_buff);
	if (is_file_empty(diff_file) == 1)
		remove(diff_file);
	else
		return (error_msg);
	return (NULL);
}

char	*test_program_and_file(const char *prog_name, const char *args, const char *file_name)
{
	int fd;
	char cmd_buff[BUF_SIZE];
	int ret;
	char test_file[BUF_SIZE];
	char *result;
	char *error_msg;
	
	generate_unique_name(test_file, "mu_test", "txt");
	error_msg = "Program failed";
	fd = open_new_file(test_file);
	cmd_buff[0] = '\0';
	sprintf(cmd_buff, "./%s %s > %s", prog_name, args, test_file);
	ret = system(cmd_buff);
	close(fd);
	/*if (ret != 0)
	{
		remove(test_file);
		return (error_msg);
	}*/
	result = assert_files(test_file, file_name);
	if (!result)
		remove(test_file);
	return (result);
}

pthread_mutex_t calculating = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t done = PTHREAD_COND_INITIALIZER;

void *expensive_call(void *function_struct)
{
	int oldtype;
	t_test_func *f;

	/* allow the thread to be killed at any time */
	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, &oldtype);

	/* ... calculations and expensive io here, for example:
	 * infinitely loop
	 */
	f = (t_test_func*)function_struct;
	f->result = f->fp();
	/* wake up the caller if we've completed in time */
	pthread_cond_signal(&done);
	return NULL;
}

static char *test_func()
{
	printf("in thread");
	return (0);
}

/* note: this is not thread safe as it uses a global condition/mutex */
static char *test_timeout(const int sec, test_func_ptr_t func)
{

	struct timespec max_wait;
	struct timespec abs_time;
	pthread_t tid;
	int err;
	t_test_func	*f;

	f = (t_test_func*) malloc(sizeof(t_test_func));
	f->fp = func;
	pthread_mutex_lock(&calculating);
	memset(&max_wait, 0, sizeof(max_wait));
	/* wait at most 2 seconds */
	max_wait.tv_sec = sec;
	/* pthread cond_timedwait expects an absolute time to wait until */
	clock_gettime(CLOCK_REALTIME, &abs_time);
	abs_time.tv_sec += max_wait.tv_sec;
	abs_time.tv_nsec += max_wait.tv_nsec;

	pthread_create(&tid, NULL, expensive_call, f);

	/* pthread_cond_timedwait can return spuriously: this should
	 * be in a loop for production code
	 */
	err = pthread_cond_timedwait(&done, &calculating, &abs_time);
	if (err == ETIMEDOUT)
		f->result = strdup("TIMEOUT");
	if (!err)
		pthread_mutex_unlock(&calculating);
	return (f->result);
}

void	test_all_with_time(const char *test_suite, int n, ...)
{
	t_test_func tf;

	printf("%s~~~~TESTING_SUITE[%s] ~~~~\n", KMAG, test_suite);
	va_list funcs;
	va_start(funcs, n);
	tf = va_arg(funcs, t_test_func);
	for (int i = 0; i < n; i++) {
		mu_run_test_timeout(tf.seconds, tf.fp);
	}
	print_results();
}

void	test_all_with_certain_time(const char *test_suite, int seconds, int n, ...)
{
	va_list funcs;

	printf("%s~~~~TESTING_SUITE[%s] WITH TIMEOUT[%d] ~~~~\n", KMAG, test_suite, seconds);
	va_start(funcs, n);
	for (int i = 0; i < n; i++) {
		mu_run_test_timeout(seconds, va_arg(funcs, test_func_ptr_t));
	}
	print_results();
}

char	*read_file_to_str(FILE *fp)
{
	char *buf;

	buf = (char*)malloc(BUF_SIZE);
	fread(buf, BUF_SIZE, 1, fp);
	fclose(fp);
	return (buf);
}

//
//char	*get_printf_output(print_func_ptr_t printf_ptr, const char *fmt, ...)
//{
//	va_list args;
//	va_start(args, fmt);
//
//	printf_ptr(fmt, args);
//	return (read_file_to_str(fp));
////}

char 	*assert_printf(print_func_ptr_t ft_printf_ptr, const char *fmt, ...)
{
	char *st_output;
	char *ft_output;
	va_list args;
	va_start(args, fmt);
	FILE *fp1;
	FILE *fp2;

	fp1 = freopen("FT_OUTPUT", "w", stdout);
	ft_printf_ptr(fmt, args);
	ft_output = read_file_to_str(fp1);
	fclose(fp1);
	remove("FT_OUTPUT");
	fp2 = freopen("ST_OUTPUT", "w", stdout);
	printf(fmt, args);
	st_output = read_file_to_str(fp2);
	fclose(fp2);
	mu_assert_str("[ft] != [st]", ft_output, st_output);
	return (0);
}

char	*make_printf_msg(const char *func_name, const char *message, const char *fmt, const char *output)
{
	char *msg;
	char *error;

	msg = (char *)malloc(BUF_SIZE);
	error = make_full_msg(message, func_name, " -> ");
	sprintf(msg, "%s : for format str = [%s] %s\n", error, fmt, output);
	free(error);
	return (msg);
}