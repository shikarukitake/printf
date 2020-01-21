//
// Created by Aletha Yellin on 06/11/2019.
//

#include "ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	va_list     args;
	size_t      i;
	int			count;

	count = 0;
    va_start(args, fmt);
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			count += call_print_func(fmt, &args, i);
			i += get_spec_format_length(fmt + i);
		}
		else
		{
			ft_putchar(fmt[i]);
			count++;
		}
		if (!fmt[i])
            break;
		i++;
	}
	va_end(args);
	return (count);
}