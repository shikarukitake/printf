//
// Created by Aletha Yellin on 22/11/2019.
//
#include <stdlib.h>
#include "ft_printf.h"

int is_precision(char ch)
{
	return (ft_isdigit(ch));
}

int		parse_precision(const char *format, t_spec *spec)
{
	int     i;
	char 	*tmp;
	int     end;

	i = 0;
	if (format[i] == '.')
	{
		spec->precision.is_dot =TRUE;
		if (format[1] == '*')
		{
			spec->precision.is_asterisk = TRUE; // get from va_arg?
			return (2);
		}
		else
		{
			end = ft_str_func_not_find(format + 1, is_precision);
			if (end <= 0)
				return (1);
			tmp = ft_strsub(format, 1, end);
			spec->precision.value = ft_atoi(tmp);
			i += ft_strlen(tmp);
			free(tmp);
			return (i + 1);
		}

	}
	return (0);
}