//
// Created by Aletha Yellin on 03/12/2019.
//

#include "minunit.h"
#include "ft_printf.h"

static char *simple_test()
{
	mu_assert_printf("test1", ft_printf, "%u", 123);
	mu_assert_printf("test2", ft_printf, "%llu", 1234);
	return (0);
}


int main()
{
	test_all("SIMPLE U", 1, extra_wh_test);
}