//
// Created by Aletha Yellin on 20/11/2019.
//

#include "ft_printf.h"

void	ft_print_str(const char *fmt, va_list args)
{
	ft_putstr(va_arg(args, char *));
}

void	ft_print_num(const char *fmt, va_list args)
{
	t_spec *spec;
	spec = parse_spec_format(fmt);
	if (spec->type)
	ft_putnbr((va_arg(args, int)));
}