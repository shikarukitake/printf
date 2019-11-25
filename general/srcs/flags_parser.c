//
// Created by Aletha Yellin on 22/11/2019.
//

#include "ft_printf.h"

int is_flag(char c)
{
	return (c == '0') || (c == '+') || (c == ' ') || (c == '#') || (c == '-');
}
//TODO: if flags are repeated?
int parse_flags(const char *format, t_spec *spec)
{
	size_t i;

	i = 0;
	while (is_flag(format[i]))
	{
		if (format[i] == '0')
			spec->flags[ZERO_FLAG_ID] = TRUE;
		else if (format[i] == '+')
			spec->flags[PLUS_FLAG_ID] = TRUE;
		else if (format[i] == '-')
			spec->flags[MINUS_FLAG_ID] = TRUE;
		else if(format[i] == '#')
			spec->flags[OCTOTHORP_FLAG_ID] = TRUE;
		else if (format[i] == ' ')
			spec->flags[WHITESPACE_FLAG_ID] = TRUE;
		i++;
	}
	return (i);
}