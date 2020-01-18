//
// Created by Aletha Yellin on 18/01/2020.
//

#include "minunit.h"
#include "ft_printf.h"

static char *o_prec_width_fit_fit_pos_af()
{
    mu_assert_printf("test1", ft_printf, "%#8.5o", 34);
    return (0);
}

static char *o_prec_width_fit_fit_pos_lj_af()
{
    mu_assert_printf("test2", ft_printf, "%#-8.5o", 34);
    return (0);
}


int main()
{
    test_all("SIMPLE O TESTS", 2,
            o_prec_width_fit_fit_pos_af,
            o_prec_width_fit_fit_pos_lj_af);
}