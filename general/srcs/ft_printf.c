//
// Created by Aletha Yellin on 06/11/2019.
//

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list     args;
	size_t      i;

    va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			call_print_func(format, &args, i); //TODO: pass args by pointer
			i += get_spec_format_length(format + i);
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (0);
}