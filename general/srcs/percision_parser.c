//
// Created by Aletha Yellin on 22/11/2019.
//
#include "ft_printf.h"

int is_precision(char ch)
{
	return (ch == '.' || ch == '*' || ft_isdigit(ch));
}

ssize_t		fill_precision(const char *format, t_spec *spec)
{
	ssize_t	i;
	char 	*tmp;
	ssize_t end;

	i = 0;
	if (format[i] == '.')
	{
		if (format[1] == '*')
			spec->precision.is_asterisk = TRUE;
		else
		{
			end =
		}
	}
	return (i);
}