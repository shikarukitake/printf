//
// Created by Aletha Yellin on 17/01/2020.
//

#include "minunit.h"
#include "ft_printf.h"
#include <limits.h>

static char *min_test()
{
    mu_assert_printf("minimum test", ft_printf, "%lld", -9223372036854775808);
    return (0);
}

int main()
{
    test_all("LONG LONG TESTS", 1, min_test);
}