//
// Created by Aletha Yellin on 13/12/2019.
//

#include "get_float.h"

t_float        get_general_float(va_list *va_args, t_conv *conv, t_spec *spec, char *buffer)
{
	t_float f;

    ((void)conv);
	init_float(&f);
	if (spec->size.id == -1 || spec->size.value[0] == 'l' || spec->size.value[0] == 'h')
		f.ld = (long double)va_arg(*va_args, double);
	else if (spec->size.value[0] == 'L')
		f.ld = va_arg(*va_args, long double);
	ft_dtoa(f.ld, buffer);
    return (f);
}