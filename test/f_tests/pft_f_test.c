//
// Created by Aletha Yellin on 19/01/2020.
//


#include "minunit.h"
#include "ft_printf.h"

static char * round_test()
{
    mu_assert_printf("test1", ft_printf, "%.0f", 1.6);
    mu_assert_printf("test2", ft_printf, "%.0f", -3.85);
    mu_assert_printf("test3", ft_printf, "%.0f", 573.924);
    mu_assert_printf("test 4", ft_printf, "%.1f", -3.85);
    return (0);
}

static char * sharp_test()
{
    mu_assert_printf("test1", ft_printf, "%#.0f", 7.4);
    mu_assert_printf("test2", ft_printf, "%#.0f", -7.4);
    return (0);
}

static char *wp_test()
{
    mu_assert_printf("test1", ft_printf, "%5.0f", -7.3);
    mu_assert_printf("test2", ft_printf, "%5.0f", 7.3);
    mu_assert_printf("test3", ft_printf, "%05.0f", 7.3);
    mu_assert_printf("test 4", ft_printf, "%+05.0f", 7.3);
    return (0);
}

static char *wh_flag_test()
{
    mu_assert_printf("test1", ft_printf, "% 5.0f", -7.3);
    mu_assert_printf("test2", ft_printf, "% 5.0f", 7.3);
    mu_assert_printf("test3", ft_printf, "% 05.0f", 7.3);
    mu_assert_printf("test 4", ft_printf, "% +05.0f", 7.3);
    return (0);
}

int main()
{
    test_all("PFT F TESTS",4, round_test, sharp_test, wp_test, wh_flag_test);
}