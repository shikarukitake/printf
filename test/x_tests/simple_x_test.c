//
// Created by Aletha Yellin on 29/11/2019.
//

#include "minunit.h"
#include "ft_printf.h"

static char *simple_test()
{
	mu_assert_printf("test1", ft_printf, "%x", 123);
	mu_assert_printf("test2", ft_printf, "%llx", 1234);
	return (0);
}

static char *simple_neg_test()
{
	mu_assert_printf("test1", ft_printf, "%x", -42);
	mu_assert_printf("test2", ft_printf, "%llx", -42);
	return (0);
}

static char *simple_zero_test()
{
    mu_assert_printf("test zero case", ft_printf, "%x", 0);
    return (0);
}



int main()
{
	test_all("SIMPLE X", 3, simple_test, simple_neg_test, simple_zero_test);
}