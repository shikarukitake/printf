//
// Created by Aletha Yellin on 18/01/2020.
//

#include "minunit.h"
#include "ft_printf.h"

static char * simple_test()
{
    mu_assert_printf("i first test", ft_printf, "% i", 9999);
    return (0);
}

int main()
{
    test_all("SIMPLE I TESTS", 1, simple_test);
}