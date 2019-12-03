//
// Created by Aletha Yellin on 03/12/2019.
//


#include "ft_printf.h"

void		get_ud(va_list va_args, t_spec *spec, char *buffer)
{
	t_conv	args;

	args = (t_conv) {0 , 10, 'a'};
	get_general_ud(va_args, args, spec, buffer);
}