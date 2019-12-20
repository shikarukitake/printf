//
// Created by dan on 20.12.19.
//

#include "ft_printf.h"
#include "minunit.h"

static char *simple_test()
{
	mu_assert_printf("test 1", ft_printf, "%a", 123);
	return (0);
}

int main()
{
	test_all("WRONG SPECIFICATOR", 1, simple_test);
}