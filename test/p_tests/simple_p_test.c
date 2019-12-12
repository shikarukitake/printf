//
// Created by Aletha Yellin on 11/12/2019.
//

#include "minunit.h"
#include "ft_printf.h"

static char *simple_test()
{
    int *ptr;
    int a;
    int b;

    ptr = &a;
    mu_assert_printf("test1", ft_printf, "%p", ptr);
    ptr = &b;
    mu_assert_printf("test2", ft_printf, "%llp", ptr);
    return (0);
}


int main()
{
    test_all("SIMPLE P", 1, simple_test);
}