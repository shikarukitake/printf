//
// Created by dan on 1/14/20.
//

#include "minunit.h"
#include "ft_printf.h"

static char *basic_test()
{
	mu_assert_printf("test1", ft_printf, "%c", 'a');
	return (0);
}

static char *width_test()
{
	mu_assert_printf("test1", ft_printf, "%5c", 'a');
	return (0);
}
//
//static char *null_char_test()
//{
//	mu_assert_printf("test-null", ft_printf, "%c is null", 0); //Wrong test because of assert function wrong
//	return (0);
//}


int main()
{
	test_all("SIMPLE C TESTS", 2, basic_test, width_test);
	return (0);
}