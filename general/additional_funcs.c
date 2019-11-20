//
// Created by Aletha Yellin on 20/11/2019.
//

#include "ft_printf.h"

void	ft_putempty(const char *fmt, va_list args)
{
	((void)fmt);
	((void)args);
}

void	ft_putpercent(const char *fmt, va_list args)
{
	(void)fmt;
	(void)(args);
	ft_putchar('%');
}