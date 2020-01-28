//
// Created by Aletha Yellin on 25/12/2019.
//
#include "minunit.h"
#include "ft_printf.h"
#include "wchar.h"

static char * simple_str_test()
{
    wchar_t star = 0x2605;
    mu_assert_printf("test1", ft_printf, "%lc", star);
    wchar_t* str = L"asdf";
    mu_assert_printf("test2", ft_printf, "%ls", str);
    return (0);
}

int main()
{
    test_all("UTF-8 STR", 1, simple_str_test);
}
