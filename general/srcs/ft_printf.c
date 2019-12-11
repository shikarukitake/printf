//
// Created by Aletha Yellin on 06/11/2019.
//

#include "ft_printf.h"

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
			call_print_func(format, args, i); //TODO: pass args by reference
			i += get_spec_format_length(format + i);
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (0);
}