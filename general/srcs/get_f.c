//
// Created by Aletha Yellin on 13/12/2019.
//

#include "get_f.h"
#include "convert.h"
#include "get_float.h"
#include "ft_float.h"

t_float		get_f(va_list *va_args, t_spec *spec, char *buffer)
{
    t_conv	args;

    args = (t_conv) {0 , 10, 'a'};
	return (get_general_float(va_args, &args, spec, buffer));
}