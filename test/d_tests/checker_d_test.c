//
// Created by Aletha Yellin on 18/01/2020.
//

#include "minunit.h"
#include "ft_printf.h"

static char *plus_zero_flag_test()
{
    mu_assert_printf("0 + test ", ft_printf, "%0+5d", 42); // -> +0042
    return (0);
}

static char *zero_flag_and_minus()
{
    mu_assert_printf("minus + 0 flag", ft_printf, "%05d", -42); // -> -0042
    return (0);
}

static char *minus_wp_flag_test()
{
    mu_assert_printf("0 fill and whitespace add", ft_printf, "%-10.5d", 4242); // --> "04242     "
    return (0);
}

static char *extra_symbol_test()
{
    mu_assert_printf("+ wp test", ft_printf, "%+10.5d", 4242); // --> "    +04242"
    mu_assert_printf("+ wp test", ft_printf, "%-+10.5d", 4242); // --> "+04242   "
    return (0);
}

static char *wp_test()
{
    mu_assert_printf("0 0wp test", ft_printf, "%03.2d", 0);
    mu_assert_printf("1 0wp test", ft_printf, "%03.2d", 1);
    mu_assert_printf("-1 0wp test", ft_printf, "%03.2d", -1);
    return (0);
}

int main()
{
    test_all("CHECKER D TESTS", 5,
            plus_zero_flag_test,
            zero_flag_and_minus,
            minus_wp_flag_test,
            extra_symbol_test,
            wp_test);
    return (0);
}