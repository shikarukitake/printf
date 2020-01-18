//
// Created by Aletha Yellin on 22/11/2019.
//


#include "width_parser.h"

int		is_width(char c)
{
	return (c == '*') || (ft_isdigit(c));
}

int		parse_width(const char *format, t_spec *spec)
{
	char	*tmp;
	ssize_t	end;

	tmp = NULL;
	end = ft_str_func_not_find(format, is_width);
	if (end == -1)
		return (0);
	tmp = ft_strsub(format, 0, end);
	if (format[0] == '*')
			spec->width.is_asterisk = TRUE;
	else
			spec->width.value = ft_atoi(tmp);
	if (ft_isdigit(format[1]) && spec->width.is_asterisk == TRUE)
	    spec->width.value = ft_atoi(tmp +1);

	free(tmp);
	return (end);
}
