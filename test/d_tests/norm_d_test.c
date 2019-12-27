//
// Created by Aletha Yellin on 27/12/2019.
//

#include "minunit.h"
#include "ft_printf.h"


static char *test_simple()
{
    int num = 1234567;
    mu_assert_printf("test1", ft_printf, "%d%", num);
    return (0);
}


int main()
{
    test_all("NORM D SUITE", 1, test_simple);
    return (0);
}