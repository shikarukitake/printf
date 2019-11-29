//
// Created by Aletha Yellin on 29/11/2019.
//

#include "minunit.h"
#include "ft_printf.h"

static char *simple_test()
{
	mu_assert_printf("test1", ft_printf, "%x", 123);
	return (0);
}


int main()
{
	test_all("SIMPLE X", 1, simple_test);
}