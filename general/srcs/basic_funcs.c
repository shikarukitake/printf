//
// Created by Aletha Yellin on 20/11/2019.
//

#include "ft_printf.h"
#include <stdlib.h>

void	ft_print_s(const char *fmt, va_list args)
{
	ft_putstr(va_arg(args, char *));
}

void	ft_print_d(const char *fmt, va_list args)
{
	t_spec		*spec;
	int 		i;
	char 		buffer[MAX_LL_BUFF_SIZE];

	i = 0;
	spec = parse_spec_format(fmt);  // may be in other place
	fill_spec_from_vargs(spec, args); //may be in other place
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
	free(spec);
}

void	ft_print_o(const char *fmt, va_list args)
{
	t_spec *spec;

	spec = parse_spec_format(fmt);
	if (spec->size.value[0] == 'l' && spec->size.value[1] == 'l')
		ft_putll(va_arg(args, long long));
	else
		ft_putnbr((va_arg(args, int)));
}


void	ft_print_x(const char *fmt, va_list args)
{
	t_spec		*spec;
	int 		i;
	char 		buffer[MAX_LL_BUFF_SIZE];

	i = 0;
	spec = parse_spec_format(fmt);  // may be in other place
	fill_spec_from_vargs(spec, args); //may be in other place
	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	if (spec->flags['-'] == TRUE)
	{
		i += print_hex_digit(args, spec);
		fill_field(i, spec);
	}
	else
	{
		get_hex_digit(args, spec, buffer);
		fill_field(ft_strlen(buffer), spec);
		if (spec->flags['+'] == TRUE)
			ft_putchar('+');
		ft_putstr(buffer);
	}
	free(spec);
}