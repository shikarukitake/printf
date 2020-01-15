//
// Created by dan on 1/15/20.
//

#include "ft_printf.h"
#include "minunit.h"


static char *extra_wh_test()
{
	mu_assert_printf("with wh", ft_printf, "% d", 42);
	mu_assert_printf("with wh", ft_printf, "% 3d", 42);
	return (0);
}

static char *extra_wh_return_test()
{
	mu_assert_printf_return("with wh", ft_printf, "% d", 42);
	return (0);
}

int main()
{
	test_all("CHECKER D TESTS", 2, extra_wh_test, extra_wh_return_test);
}