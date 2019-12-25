//
// Created by Aletha Yellin on 13/12/2019.
//
#include "float_convert.h"
#include "get_float.h"
#include "ft_float.h"

t_float        get_general_float(va_list *va_args, t_conv *conv, t_spec *spec, char *buffer)
{
	t_float f;

	init_float(&f);
	if (spec->size.id == -1)
	{
		f.d = va_arg(*va_args, double);
		ft_dtoa_base(f.d, buffer, conv->base, conv->a);
	}
	else if (spec->size.value[0] == 'L')
	{
		f.ld = va_arg(*va_args, long double);
		ft_ldtoa_base(f.ld, buffer, conv->base, conv->a);
	}
    return (f);
}