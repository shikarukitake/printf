//
// Created by Aletha Yellin on 06/11/2019.
//

#include "ft_stdio.h"
#include <stdarg.h>

int		ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	size_t i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				ft_putstr(va_arg(args, char*));
		}
		else
		{
			ft_putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (0);
}