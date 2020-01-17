//
// Created by Aletha Yellin on 17/01/2020.
//

#include "minunit.h"
#include "ft_printf.h"

static char *basic_test()
{
    mu_assert_printf("first short test", ft_printf, "%hd", 32767);
    return (0);
}

static char *max_min_test()
{
    mu_assert_printf("min short test", ft_printf, "%hd", 32768);
    return (0);
}

int main()
{
    test_all("SHORT D TESTS", 2, basic_test, max_min_test);
}
