//
// Created by Aletha Yellin on 20/11/2019.
//

#include "ft_printf.h"

void	ft_print_empty(t_spec *spec, va_list args)
{
	((void)spec);
	((void)args);
}

void	ft_print_percent(t_spec *spec, va_list args)
{
	((void)spec);
	(void)(args);
	ft_putchar('%');
}