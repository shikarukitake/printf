//
// Created by Aletha Yellin on 20/11/2019.
//

#include "basic_print.h"

int		ft_print_s(t_spec* spec, va_list *args)
{
	char *tmp;
    int i;

    i = 0;
	tmp = va_arg(*args, char *);
	if (spec->precision.value == -1)
	{
        ft_putstr(tmp);
        return (ft_strlen(tmp));
    }
	else
    {
	    while (i < spec->precision.value)
        {
	        ft_putchar(tmp[i]);
	        i++;
        }
	    return (i);
    }
}

int		ft_print_c(t_spec* spec, va_list *args)
{
	ft_putchar(va_arg(*args, int));
	return (1);
}

int	ft_print_d(t_spec *spec, va_list *args)
{
	char 		buffer[MAX_LL_BUFF_SIZE];

	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	get_sd(args, spec, buffer);
	return (ft_put_sd_buf(buffer, spec));
}

int    ft_print_p(t_spec *spec, va_list *args)
{
    char        buffer[MAX_P_BUFF_SIZE];

    ft_bzero(buffer, MAX_P_BUFF_SIZE);
    get_p(args, spec, buffer);
	return (ft_put_hex_buf(buffer, spec));
}