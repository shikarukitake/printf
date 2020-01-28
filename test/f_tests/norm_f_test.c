//
// Created by Aletha Yellin on 19/01/2020.
//

#include "minunit.h"
#include "ft_printf.h"

static char * norm_test()
{
    double d;

    d = 0.333;
    mu_assert_printf("test1", ft_printf, "%5.2f", d);
    return (0);
}

static char *null_test()
{
    double d = 0.0;
    mu_assert_printf("just 0.0", ft_printf, "%f", d);
    mu_assert_printf("0.0 and zero precision", ft_printf, "%.0f %.f", d, d);
    return (0);
}

int main()
{
    test_all("NORM F TESTS", 2, norm_test, null_test);
}