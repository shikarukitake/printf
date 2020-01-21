//
// Created by Aletha Yellin on 13/12/2019.
//

#include "get_f.h"

long double     get_f(va_list *va_args, t_spec *spec, char *buffer)
{
	return get_general_float(va_args, spec, buffer);
}