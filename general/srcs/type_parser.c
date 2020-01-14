//
// Created by Aletha Yellin on 25/11/2019.
//

#include "printf_constatns.h"
#include "specificator.h"
#include "libft.h"


int find_percent(const char *format)
{
	int		next_percent_pos;
	int		type_pos;

	next_percent_pos = ft_strchri(format + 1, '%');
	if (next_percent_pos != -1)
	{

	}
}


int		parse_type(const char *format, t_spec *spec)
{
	char	*ptr;


	ptr = ft_strchr(FT_PRINTF_SPEC_TYPES, format[0]);
	if (!ptr)
	{

		if(format[0] == '%')
		{
			spec->type = '%';
			return (1);
		}
		spec->type = -1;
		return (0);
	}
	else
		spec->type = *ptr;
	return (1);
}