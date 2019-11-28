//
// Created by Aletha Yellin on 20/11/2019.
//

#include "ft_printf.h"

void	ft_print_empty(const char *fmt, va_list args)
{
	((void)fmt);
	((void)args);
}

void	ft_print_percent(const char *fmt, va_list args)
{
	((void)fmt);
	(void)(args);
	ft_putchar('%');
}