//
// Created by Aletha Yellin on 21/01/2020.
//

#include "minunit.h"
#include "ft_printf.h"
#include <limits.h>

static char *test_simple()
{
	mu_assert_printf("test1", ft_printf, "%D", INT_MIN);
	mu_assert_printf("test2", ft_printf, "%D", INT_MAX + 1);
	return (0);
}


int main()
{
	test_all("SIMPLE D TESTS", 2 ,test_simple, test_two_d);
	return (0);
}