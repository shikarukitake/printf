//
// Created by dan on 21.12.19.
//

#include "minunit.h"
#include "ft_printf.h"

static char *simple_test()
{
	mu_assert_printf_return("simple1", ft_printf, "%s", "Hello, world");
	return (0);
}

static char *nums_test()
{
    mu_assert_printf_return("d nums return", ft_printf, "%d", 12345);
    return (0);
}

static char *nw_test()
{
	mu_assert_printf_return("d and wh", ft_printf, "%10d", 12345);
	return (0);
}

int main()
{
	test_all("RETURN VALUES", 3, extra_wh_test, nums_test, nw_test);
}