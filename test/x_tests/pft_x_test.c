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

static char *x_prec_width_fit_nofit_pos_lj_af()
{
    mu_assert_printf("right order", ft_printf, "%#-2.7x", 3267);
    return (0);
}

static char *x_prec_width_ff_pos_zp_af()
{
    mu_assert_printf("extra wh", ft_printf, "%#08.5x", 34);
    return (0);
}

static char *x_prec_width_nf_pos_zp_af()
{
    mu_assert_printf("wxtra wh", ft_printf, "%#08.3x", 8375);
    return (0);
}

static char *x_prec0val0_wafj()
{
    mu_assert_printf("must be empty", ft_printf, "%#-5.0x", 0);
    mu_assert_printf("must be empty", ft_printf, "%#-5.x", 0);
    return (0);
}

int main()
{
    test_all("PFT X TESTS", 5,
            x_prec_width_fit_fit_pos_af,
            x_prec_width_fit_nofit_pos_lj_af,
            x_prec_width_ff_pos_zp_af,
            x_prec_width_nf_pos_zp_af,
            x_prec0val0_wafj);
}