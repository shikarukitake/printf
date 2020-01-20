//
// Created by Aletha Yellin on 19/01/2020.
//

#include "minunit.h"
#include "ft_printf.h"
#include <float.h>
static char * small_number_test()
{
    mu_assert_printf("test1", ft_printf, "{%f}{%lf}{%Lf}", 1.42, 1.42, 1.42l);
    return (0);
}

static char *big_number_test()
{
    mu_assert_printf("test1", ft_printf, "{%Lf}", 1212121.12121L);
//    mu_assert_printf("test2", ft_printf, "{%lf}", 1444565444646.6465424242242);
//    mu_assert_printf("test3", ft_printf, "{%Lf}", 1444565444646.6465424242242);

    return (0);
}

int main()
{
    test_all("MOULI F TESTS",1, big_number_test);
}