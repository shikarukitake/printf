//
// Created by dan on 20.12.19.
//

#include "ft_printf.h"
#include "minunit.h"

//static char *extra_wh_test()
//{
//	mu_assert_printf("test 1", ft_printf, "%a", 123);
//	return (0);
//}

static char *no_spec_test()
{
	mu_assert_printf("test without specificator", ft_printf, "%-123443   ", MU_NULL);
	return (0);
}

static char *no_spec_test2()
{
	mu_assert_printf("test without specificator", ft_printf, "%-123443", MU_NULL);
	return (0);
}

//static char *spec_after_test()
//{
//	const char *fmt = "%-1234   %d";
//	int d = 123;
//
//	mu_assert_printf("test with specificator ahead", ft_printf, fmt, d);
//	return (0);
//}

int main()
{
	test_all("WRONG SPECIFICATOR", 2, no_spec_test, no_spec_test2);
}