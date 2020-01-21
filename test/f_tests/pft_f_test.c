//
// Created by Aletha Yellin on 19/01/2020.
//


#include "minunit.h"
#include "ft_printf.h"
#include <float.h>

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


static char *conversion_test()
{

    mu_assert_printf("lol", ft_printf, "%f", 12222.5);
    return (0);
}

static char *strange_size_spec()
{
    mu_assert_printf("hf", ft_printf, "%hf", 32.22);
    return (0);
}

#define DBL_INF    0x7FF0000000000000
#define DBL_NINF   0xFFF0000000000000
#define DBL_NAN    0x7FF0000000100000
#define DBL_PZERO  0x0000000000000000
#define DBL_NZERO  0x8000000000000000

static char *sp_test()
{
    double special;
    *((unsigned long *)(&special)) = DBL_INF;

    mu_assert_printf(" inf", ft_printf, "% .7f", special);
    return (0);
}

int main()
{
    test_all("PFT F TESTS",7,
            round_test,
            sharp_test,
            wp_test,
            wh_flag_test,
            conversion_test,
            strange_size_spec,
            sp_test);
}