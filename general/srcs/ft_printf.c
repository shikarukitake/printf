//
// Created by Aletha Yellin on 06/11/2019.
//

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list     args;
	size_t      i;
	int			count;

	count = 0;
    va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += call_print_func(format, &args, i); //TODO: pass args by pointer
			i += get_spec_format_length(format + i);
		}
		else
		{
			ft_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}