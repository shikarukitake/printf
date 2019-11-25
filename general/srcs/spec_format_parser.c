//
// Created by Aletha Yellin on 20/11/2019.
//

#include "ft_printf.h"

ssize_t		get_spec_format_length(const char *format)
{
	ssize_t end_of_format;
	end_of_format = ft_strcspn(format, g_type_specs);
	return (end_of_format == -1 ? 1 : end_of_format);
}

t_spec	*parse_spec_format(const char *spc_fmt)
{
	t_spec *spec;
	size_t  i;

	i = 0;
	spec = init_spec();
	if (!spec)
		return (NULL);
	i += parse_flags(spc_fmt, spec);
	i += parse_width(spc_fmt + i, spec);
	i += parse_precision(spc_fmt + i, spec);
	i += parse_size(spc_fmt + i, spec);
	if (!parse_type(spc_fmt + i, spec))
		ft_exit(spec, "there was no type"); // TODO: CHANGE LATER
	return (spec);
}