//
// Created by Aletha Yellin on 20/11/2019.
//

#include "ft_printf.h"


void	ft_print_s(t_spec* spec, va_list args)
{
	ft_putstr(va_arg(args, char *));
}

void	ft_print_d(t_spec *spec, va_list args)
{
	char 		buffer[MAX_LL_BUFF_SIZE];

	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	get_signed_digit(args, spec, buffer);
	ft_put_sd_buf(buffer, spec);
}

void	ft_print_o(t_spec *spec, va_list args)
{
	if (spec->size.value[0] == 'l' && spec->size.value[1] == 'l')
		ft_putll(va_arg(args, long long));
	else
		ft_putnbr((va_arg(args, int)));
}


void	ft_print_x(t_spec *spec, va_list args)
{
	char 		buffer[MAX_LL_BUFF_SIZE];

	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	get_hex_digit(args, spec, buffer);
	ft_put_sd_buf(buffer, spec);
}