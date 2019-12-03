//
// Created by Aletha Yellin on 06/11/2019.
//

#include "minunit.h"
#include "ft_printf.h"


static char *general_test()
{
	mu_assert_printf("basic format test", ft_printf, "%s", "Hello, world!");
	return (0);
}

static char *another_general_test()
{
	mu_assert_printf("two arguments", ft_printf, "%s = %s", "wat", "WTF?!");
	return (0);
}

static char *check_number()
{
	mu_assert_printf("two arguments", ft_printf, "%d", 1);
	return (0);
}

int main()
{
	test_all("another_general_test", 3, another_general_test, general_test, check_number);
}