//
// Created by dan on 20.12.19.
//

#include "float_print.h"

int    ft_print_f(t_spec *spec, va_list *args)
{
	char	buffer[MAX_FLOAT_BUFF_SIZE];
	t_float	f;

	ft_bzero(buffer, MAX_FLOAT_BUFF_SIZE);
	f = get_f(args, spec, buffer);
	return (ft_put_float_buf(buffer, spec, &f));
}