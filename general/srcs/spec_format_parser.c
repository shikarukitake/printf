//
// Created by Aletha Yellin on 20/11/2019.
//

#include "spec_format_parser.h"

static int         g_was_color = 0;

void		fill_spec_from_vargs(t_spec *spec, va_list *vargs)
{
	if (spec->width.is_asterisk == TRUE)
		spec->width.value = va_arg(*vargs, int);
	else if (spec->precision.is_asterisk == TRUE)
		spec->precision.value = va_arg(*vargs, int);
}

int 	is_just_percent(const char *format)
{
	int type_pos;
	int next_percent_pos;
	
	next_percent_pos = ft_strchri(format + 1, '%');
	type_pos = ft_strcspn(format, FT_PRINTF_SPEC_TYPES);
	
	if (next_percent_pos == -1 && type_pos == -1)
		return (1);
	else
		return (0);
}

int		is_spec_format(const char *format)
{

	int type_pos;
	int next_percent_pos;

	next_percent_pos = ft_strchri(format + 1, '%');
	type_pos = ft_strcspn(format, FT_PRINTF_SPEC_TYPES);
	if (next_percent_pos != -1 && type_pos != -1)
	{
		if (type_pos > next_percent_pos)
			return (0);
		else
			return (1);
	}
	if (next_percent_pos == -1 && type_pos != -1)
		return (1);
	return (0);
}

int     get_spec_format_length(const char *format)
{
	int end_of_format;
    if (g_was_color)
    {
        g_was_color = 0;
        return (5);
    }
	if (is_spec_format(format))
		end_of_format = ft_strcspn(format, FT_PRINTF_SPEC_TYPES);
	else
		end_of_format = ft_strchri(format + 1, '%') + 1;
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
	parse_type(spc_fmt +i, spec);
//	if (!parse_type(spc_fmt + i, spec))
//		ft_exit(spec, "there was no type\n"); // TODO: CHANGE LATER
	return (spec);
}