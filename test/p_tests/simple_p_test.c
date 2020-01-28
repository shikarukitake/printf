//
// Created by Aletha Yellin on 11/12/2019.
//

#include "minunit.h"
#include "ft_printf.h"

static char *simple_test()
{
    int *ptr;
    int a;
    int b;

    ptr = &a;
    mu_assert_printf("test1", ft_printf, "%p", ptr);
    ptr = &b;
    mu_assert_printf("test2", ft_printf, "%llp", ptr);
    return (0);
}

static char *zero_test()
{
    mu_assert_printf("zero pointer test", ft_printf, "%p", 0);
    mu_assert_printf("zero pointer and precision", ft_printf, "%.5p", 0);
    return (0);
}

static char *null_test()
{
    mu_assert_printf("null test", ft_printf, "%.0p, %.p", 0, 0);
    mu_assert_printf("null test 2", ft_printf, "%.p, %.0p", 0, 0);
    return (0);
}



int main()
{
	test_all("SIMPLE P", 3, simple_test, zero_test, null_test);
}