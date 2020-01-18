//
// Created by Aletha Yellin on 18/01/2020.
//

#include "minunit.h"
#include "ft_printf.h"

static char *mouli_test()
{
    mu_assert_printf("wildcard for min width negative", ft_printf, "{%*d}", -5, 42 );
    mu_assert_printf("wildcard for min_width_positive", ft_printf, "%*.*d", 0, 3, 0);
    mu_assert_printf("digit_wildcard and min_width_value3", ft_printf, "{%*.3d}", 5, 0);
    mu_assert_printf("wildcard for precision string negative", ft_printf, "{%.*s}", -5, "42");
    return (0);
}


int main()
{
    test_all("BONUS: WILDCARD", 1, mouli_test);
    return (0);
}