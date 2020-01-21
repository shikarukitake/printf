//
// Created by Aletha Yellin on 13/12/2019.
//

#include "get_float.h"

long double        get_general_float(va_list *va_args, t_spec *spec, char *buffer)
{
    long double value;

    value  = 0.0;
    if (spec->size.id == -1 || spec->size.value[0] == 'l' || spec->size.value[0] == 'h')
		value = (long double)va_arg(*va_args, double);
    else if (spec->size.value[0] == 'L')
		value = va_arg(*va_args, long double);
	ft_dtoa(value, buffer);
    return value;
}