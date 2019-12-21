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

int main()
{
	test_all("RETURN VALUES", 1, simple_test);
}