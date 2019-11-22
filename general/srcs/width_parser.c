//
// Created by Aletha Yellin on 22/11/2019.
//

#include "ft_printf.h"

int is_width(char c)
{
	return (c == '*') || (ft_isdigit(c));
}

int fill_width(const char *format, t_spec *spec)
{
	char	*tmp;
	tmp = ft_strsub(format, 0, ft_strcspn(format, g_type_specificators));
	if (format[0] == '*')
			spec->width.is_asterisk = TRUE;
	else
			spec->width.value = ft_atoi(tmp);
	return (i);
}
