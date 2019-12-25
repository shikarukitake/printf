//
// Created by Aletha Yellin on 20/11/2019.
//

#include "spec_format_parser.h"

int         g_was_color = 0;

void		fill_spec_from_vargs(t_spec *spec, va_list *vargs)
{
	if (spec->width.is_asterisk == TRUE)
		spec->width.value = va_arg(*vargs, int);
	else if (spec->precision.is_asterisk == TRUE)
		spec->precision.value = va_arg(*vargs, int);
}

int     get_spec_format_length(const char *format)
{
	int end_of_format;
    if (g_was_color)
    {
        g_was_color = 0;
        return (5);
    }
	end_of_format = ft_strcspn(format, g_type_specs);
	return (end_of_format == -1 ? 1 : end_of_format);
}

t_spec	*parse_spec_format(const char *spc_fmt)
{
	t_spec  *spec;
	size_t  i;

	i = 0;
	spec = init_spec();
	if (!spec)
		return (NULL);
	if (parse_color(spc_fmt, spec) > 0)
	{
	    g_was_color = 1;
	    spec->type = 'q';
        return (spec);
    }
	i += parse_flags(spc_fmt + i, spec);
	i += parse_width(spc_fmt + i, spec);
	i += parse_precision(spc_fmt + i, spec);
	i += parse_size(spc_fmt + i, spec);
	if (!parse_type(spc_fmt + i, spec))
		ft_exit(spec, "there was no type"); // TODO: CHANGE LATER
	return (spec);
}