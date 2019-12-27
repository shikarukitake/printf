//
// Created by Aletha Yellin on 22/11/2019.
//

#include "ft_printf.h"

int is_flag(char c)
{
	return (ft_strchr(g_flags, c) != NULL);
}

//TODO: if flags are repeated?
int parse_flags(const char *format, t_spec *spec)
{
	size_t i;

	i = 0;
	while (is_flag(format[i]))
		spec->flags[(int)format[i++]] = TRUE;
	return (i);
}