//
// Created by Aletha Yellin on 20/11/2019.
//

#include "ft_printf.h"

ssize_t		get_format_spec_length(const char *format)
{
	ssize_t end_of_format;
	end_of_format = ft_strcspn(format, g_type_specificators);
	return (end_of_format == -1 ? 1 : end_of_format);
}

t_spec	*parse_format(const char *format)
{
	t_spec *spec;
	size_t  i;

	i = 0;
	spec = ft_memalloc(sizeof(t_spec));
	i += fill_flags(format, spec);
	i += fill_width(format + i, spec);
	i += fill_precision(format + i, spec);

	return (spec);
}