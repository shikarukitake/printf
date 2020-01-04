//
// Created by Aletha Yellin on 27/12/2019.
//

#include "minunit.h"
#include "ft_printf.h"


static char *test_simple()
{
    int num = 1234567;
    mu_assert_printf("test1", ft_printf, "%d%", num);
    mu_assert_printf("test2", ft_printf, "%.*d", 10, num);
    return (0);
}

static char *test_gap()
{
	int num = 1234578;

	mu_assert_printf("test1", ft_printf, "%10.10d", num);
	mu_assert_printf("test2", ft_printf, "%5d", num);
	mu_assert_printf("test3", ft_printf, "%-10d", num);
	return (0);
}

static char *strange_test()
{
	int num = 1234567;

	mu_assert_printf("test1", ft_printf, "%10.5d", num);
	mu_assert_printf("test2", ft_printf, "%5.10d", num);
	return (0);
}

static char *flags_test()
{
	int num = 1234567;

	mu_assert_printf("test1", ft_printf, "%+10.d", num);
	mu_assert_printf("test_zero", ft_printf, "%010.d", num);
	mu_assert_printf("test_zero_2", ft_printf, "%010.5d", num);
	mu_assert_printf("test_wh", ft_printf, "% 10d", num);
	mu_assert_printf("test_wh_2", ft_printf, "% 10.5d", num);
	//mu_assert_printf("test_wh_3", ft_printf, "% .10d", num); - very strange test result
	return (0);
}

int main()
{
    test_all("NORM D SUITE", 4, test_simple, test_gap, strange_test, flags_test);
    return (0);
}