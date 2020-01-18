//
// Created by Aletha Yellin on 18/01/2020.
//

#include "minunit.h"
#include "ft_printf.h"

static char * x_prec_width_fit_fit_pos_af()
{
    mu_assert_printf("shift", ft_printf, "%#8.5x", 34);
    return (0);
}

int main()
{
    test_all("PFT X TESTS", 1,
            x_prec_width_fit_fit_pos_af);
}