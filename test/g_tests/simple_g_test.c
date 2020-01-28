//
// Created by Aletha Yellin on 21/01/2020.
//
//
// Created by Aletha Yellin on 13/12/2019.
//

#include "minunit.h"
#include "ft_printf.h"

static char *test_simple()
{
	double d;

	d =  881.3455432;
	mu_assert_printf("test1", ft_printf, "%g", d);
	d = 881.3455432;
	mu_assert_printf("test2", ft_printf, "%g", d);
	return (0);
}

static char *test_simple2()
{
	double d;

	d =  0.15625;
	mu_assert_printf("test1", ft_printf, "%g", d);
	d = -0.123;
	mu_assert_printf("test2", ft_printf, "%g", d);
	return (0);
}

static char *test_simple3()
{
	double d;

	d = 0.999999;
	mu_assert_printf("test1", ft_printf, "%g", d);
	d = 0.9999999;
	mu_assert_printf("test2", ft_printf, "%g", d);
	return (0);
}

static char *test_simple4()
{
	double d;

	d = 0.000039;
	mu_assert_printf("test1", ft_printf, "%g", d);
	return (0);
}

static char *test_simple5()
{
	double d;

	d = 43.4399999;
	mu_assert_printf("test1", ft_printf, "%g", d);
	return (0);
}

static char *test_simple6()
{
	double d;

	d = 0.99999999;
	mu_assert_printf("test nines", ft_printf, "%g", d);
	return (0);
}

static char *test_simple7()
{
	double d;

	d = 23.999999999;
	mu_assert_printf("test nines", ft_printf, "%g", d);
	return (0);
}

static char *test_simple8()
{
	double d;

	d = 999.99999999;
	mu_assert_printf("test nines", ft_printf, "%g", d);
	return (0);
}

static char *test_simple9()
{
	double d;

	d = 999.99999999;
	mu_assert_printf("test nines", ft_printf, "%10g", d);
	return (0);
}

static char *test_simple10()
{
	double d;

	d = 10000;
	mu_assert_printf("test nines", ft_printf, "%g", d);
	return (0);
}

static char *test_simple11()
{
	double d;

	d = 23.999999999;
	mu_assert_printf("test nines", ft_printf, "%#g", d);
	return (0);
}

int main()
{
	test_all("SIMPLE G TESTS", 11,
			test_simple,
			test_simple2,
			test_simple3,
			test_simple4,
			test_simple5,
			test_simple6,
			test_simple7,
			test_simple8,
			test_simple9,
			test_simple10,
			test_simple11);
	return (0);
}