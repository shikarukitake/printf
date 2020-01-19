//
// Created by dan on 20.12.19.
//

#include "print_float.h"

int    ft_print_f(t_spec *spec, va_list *args)
{
	char	buffer[MAX_FLOAT_BUFF_SIZE];

	ft_bzero(buffer, MAX_FLOAT_BUFF_SIZE);
	get_f(args, spec, buffer);
	return (print_f_buf(buffer, spec));
}