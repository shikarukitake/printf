//
// Created by Aletha Yellin on 25/11/2019.
//

#include "ft_printf.h"

int		parse_type(const char *format, t_spec *spec)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = ft_strchr(g_type_specs, format[i]);
	if (!ptr)
	{
		spec->type = -1;
		return (0);
	}
	else
		spec->type = *ptr;
	return (1);
}