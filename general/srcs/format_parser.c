//
// Created by Aletha Yellin on 20/11/2019.
//

#include "ft_printf.h"

int		get_format_spec_length(const char *format)
{
	return (ft_strcspn(format, g_type_specificators));
}

t_spec	*parse_format(const char *format)
{
	t_spec *spec;
	size_t  i;

	i = 0;
	spec = ft_memalloc(sizeof(t_spec));
	i += fill_flags(format, spec);
	i += fill_width(format, spec);
}