//
// Created by dan on 20.12.19.
//

#include "print_float.h"

int    ft_print_f(t_spec *spec, va_list *args)
{
	char	*buffer;
    int     count;

	buffer = ft_memalloc(MAX_FLOAT_BUFF_SIZE * 2 + 10);
	get_f(args, spec, buffer);
	count = print_f_buf(buffer, spec);
	free(buffer);
	return (count);
}

int    ft_print_e(t_spec *spec, va_list *args)
{
	char	*buffer;
	int     count;

	buffer = ft_memalloc(MAX_FLOAT_BUFF_SIZE * 2 + 10);
	get_f(args, spec, buffer);
	count = print_e_buf(buffer, spec, 'e');
	free(buffer);
	return (count);
}

int    ft_print_E(t_spec *spec, va_list *args)
{
	char	*buffer;
	int     count;

	buffer = ft_memalloc(MAX_FLOAT_BUFF_SIZE * 2 + 10);
	get_f(args, spec, buffer);
	count = print_e_buf(buffer, spec, 'E');
	free(buffer);
	return (count);
}