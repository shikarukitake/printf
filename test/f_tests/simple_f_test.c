//
// Created by Aletha Yellin on 13/12/2019.
//

#include "minunit.h"
#include "ft_printf.h"

static char *test_simple()
{
	double d;

	d =  881.15625;
	//mu_assert_printf("test1", ft_printf, "%f", 123);
	mu_assert_printf("test2", ft_printf, "%f", d);
	return (0);
}

int main()
{
    test_all("SIMPLE F TESTS", 1, test_simple);
    return (0);
}