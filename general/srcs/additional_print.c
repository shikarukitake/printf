//
// Created by Aletha Yellin on 20/11/2019.
//

#include "ft_printf.h"

int	ft_print_empty(t_spec *spec, va_list *args)
{
	((void)spec);
	((void)args);
	return (0);
}

int	ft_print_percent(t_spec *spec, va_list *args)
{
	((void)spec);
	(void)(args);
	ft_putchar('%');
	return (1);
}