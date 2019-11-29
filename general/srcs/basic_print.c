//
// Created by Aletha Yellin on 20/11/2019.
//

#include "ft_printf.h"
#include <stdlib.h>

void	ft_print_s(t_spec* spec, va_list args)
{
	ft_putstr(va_arg(args, char *));
}

void	ft_print_d(t_spec *spec, va_list args)
{
	int 		i;
	char 		buffer[MAX_LL_BUFF_SIZE];

	i = 0;
	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	if (spec->flags['-'] == TRUE)
	{
		i += print_signed_digit(args, spec);
		fill_field(i, spec);
	}
	else
	{
		get_signed_digit(args, spec, buffer);
		fill_field(ft_strlen(buffer), spec);
		if (spec->flags['+'] == TRUE)
			ft_putchar('+');
		ft_putstr(buffer);
	}
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
	int 		i;
	char 		buffer[MAX_LL_BUFF_SIZE];

	i = 0;
	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	get_hex_digit(args, spec, buffer);
	if (spec->flags['-'] == TRUE)
	{
		i += ft_strlen(buffer);
		ft_putstr(buffer);
		fill_field(i, spec);
	}
	else
	{
		fill_field(ft_strlen(buffer), spec);
		if (spec->flags['+'] == TRUE)
			ft_putchar('+');
		ft_putstr(buffer);
	}
}