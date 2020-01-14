//
// Created by Aletha Yellin on 25/11/2019.
//

#include "printf_constants.h"
#include "specificator.h"
#include "libft.h"

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