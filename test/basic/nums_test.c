//
// Created by Sole Dagger on 12/11/2019.
//
#include "minunit.h"
#include "ft_printf.h"

static char *check_number()
{
	mu_assert_printf("two arguments", ft_printf, "%d", 1);
	return (0);
}

static char *check_long_simple_number()
{
	mu_assert_printf("long long num", ft_printf, "num = %lld", 2147483649);
	return (0);
}

int main()
{
	test_all("another_general_test", 2, check_number, check_long_simple_number);
}