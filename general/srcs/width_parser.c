//
// Created by Aletha Yellin on 22/11/2019.
//

#include <stdlib.h>
#include "ft_printf.h"

int		is_width(char c)
{
	return (c == '*') || (ft_isdigit(c));
}

/*
 ** Returns the position of the character in the string for which the function returned 0
*/
// TODO: move to util.h or to libft.h
ssize_t 	ft_str_func_find(const char *str, int(*func)(char ch))
{
	ssize_t i;

	i = 0;
	while (str[i])
	{
		if (!func(str[i]))
			return (i);
		i++;
	}
	return (-1);
}


int		fill_width(const char *format, t_spec *spec)
{
	char	*tmp;
	ssize_t	end;

	tmp = NULL;
	end = ft_str_func_find(format, is_width);
	if (end == -1)
		return (0);
	tmp = ft_strsub(format, 0, end);
	if (format[0] == '*')
			spec->width.is_asterisk = TRUE;
	else
			spec->width.value = ft_atoi(tmp);
	free(tmp);
	return (end);
}
