//
// Created by Aletha Yellin on 13/12/2019.
//

#include "minunit.h"
#include "ft_printf.h"

static char *test_simple()
{
	double d;

	d =  881.15625;
	mu_assert_printf("test1", ft_printf, "%f", d);
	d = -881.123;
    mu_assert_printf("test2", ft_printf, "%f", d);
	return (0);
}

static char *test_simple2()
{
    double d;

    d =  0.15625;
    mu_assert_printf("test1", ft_printf, "%f", d);
    d = -0.123;
    mu_assert_printf("test2", ft_printf, "%f", d);
    return (0);
}

static char *test_simple3()
{
    double d;

    d = 0.999999;
    mu_assert_printf("test1", ft_printf, "%f", d);
    d = 0.9999999;
    mu_assert_printf("test2", ft_printf, "%f", d);
    return (0);
}

static char *test_simple4()
{
    double d;

    d = 0.000039;
    mu_assert_printf("test1", ft_printf, "%f", d);
    return (0);
}

static char *test_simple5()
{
    double d;

    d = 43.4399999;
    mu_assert_printf("test1", ft_printf, "%f", d);
    return (0);
}


int main()
{
    test_all("SIMPLE F TESTS", 5, test_simple, test_simple2, test_simple3, test_simple4, test_simple5);
    return (0);
}