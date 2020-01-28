//
// Created by Aletha Yellin on 28/11/2019.
//

#include "minunit.h"
#include "ft_printf.h"

static char *test_simple()
{
	mu_assert_printf("test1", ft_printf, "%-+5ld", 123);
	return (0);
}

static char *test_two_d()
{
    mu_assert_printf("test with 2 digits", ft_printf, "%d != %d", 202020, 20);
    return (0);
}

int main()
{
	test_all("SIMPLE D TESTS", 2 ,test_simple, test_two_d);
	return (0);
}