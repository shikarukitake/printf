//
// Created by Aletha Yellin on 12/11/2019.
//

#include "minunit.h"
#include "ft_printf.h"

static char *basic_str_test(void)
{
	mu_assert_printf("first test", ft_printf, "%s", "Hello");
    mu_assert_printf("second test", ft_printf, "%.5s", "Hello World");
    return (0);
}

static char *width_str_test(void)
{
	mu_assert_printf("width less the len", ft_printf, "%2s world", "hello");
	mu_assert_printf("width more the len", ft_printf, "%10s world", "hello");

	return (0);
}

static char *flags_str_test(void)
{
	mu_assert_printf("0 flag", ft_printf, "%010s world", "hello");
	return (0);
}

static char *null_str_test(void)
{
	mu_assert_printf("null test", ft_printf, "%s", MU_NULL);
	return (0);
}

static char *wp_str_test(void)
{
	mu_assert_printf("precision test", ft_printf, "%0.5s world", "hello");
	mu_assert_printf("width and precision test", ft_printf, "%10.5s world", "hello");
	mu_assert_printf("width and precision test 2", ft_printf, "%5.10s world", "hello");
	mu_assert_printf("width and precision test", ft_printf, "%3.2s world", "hello");
	mu_assert_printf("width and precision test 2", ft_printf, "%2.3s world", "hello");

	return (0);
}

int main()
{
	test_all("SIMPLE STR PRINTF TESTS", 5, basic_str_test, width_str_test, flags_str_test, null_str_test, wp_str_test);
	return (0);
}