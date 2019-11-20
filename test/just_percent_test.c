//
// Created by Aletha Yellin on 12/11/2019.
//
#include "minunit.h"
#include "ft_printf.h"

static char *simple_test()
{
	mu_assert_printf("two percents", ft_printf, "%%", MU_NULL);
	return (0);
}


int main(void)
{
	test_all("JUST PERCENT", 1, simple_test);
	return (0);
}