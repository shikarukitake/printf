//
// Created by Aletha Yellin on 25/11/2019.
//

#include "ft_printf.h"

ssize_t 	parse_size(const char *format, t_spec *spec)
{
	ssize_t	i;
	char 	*tmp;
	char j;

	i = -1;
	j = 0;
	tmp = spec->size.value;
	while (!ft_strchr(g_type_specs, format[++i]))
		tmp[j++] = format[i];
	tmp[j] = '\0';
	spec->size.id = ft_arr_find(g_size_specs, MAX_SIZE_SPECS, tmp);
	return (ft_strlen(tmp));
}