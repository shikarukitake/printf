//
// Created by Aletha Yellin on 25/11/2019.
//

#include "size_parser.h"

int parse_size(const char *format, t_spec *spec)
{
	int		i;
	char 	*tmp;
	int     j;

	i = -1;
	j = 0;
	tmp = spec->size.value;
	if(format[0] == '%')
		return (0);
	while (!ft_strchr(g_type_specs, format[++i]))
		tmp[j++] = format[i];
	tmp[j] = '\0';
	spec->size.id = ft_arr_find(g_size_specs, MAX_SIZE_SPECS, tmp);
	return (ft_strlen(tmp));
}