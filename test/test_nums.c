//
// Created by Sole Dagger on 12/11/2019.
//
#include "minunit.h"
#include "ft_stdio.h"

static char *check_number()
{
	mu_assert_printf("two arguments", ft_printf, "%d", 1);
	return (0);
}

int main()
{
	test_all("another_general_test", 1, check_number);
}