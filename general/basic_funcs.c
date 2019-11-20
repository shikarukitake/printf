//
// Created by Aletha Yellin on 20/11/2019.
//

#include "ft_printf.h"

void	ft_putstr_args(const char *fmt, va_list args)
{
	ft_putstr(va_arg(args, char *));
}

void	ft_putnum_args(const char *fmt, va_list args)
{
	ft_putnbr((va_arg(args, int)));
}