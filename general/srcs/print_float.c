//
// Created by Aletha Yellin on 26/12/2019.
//

int	ft_put_float_buf(char *buf, t_spec *spec, t_float *f)
{
    if (is_need_zero(f))
        ft_putchar('0');
    return(ft_put_sd_buf(buf, spec));
}