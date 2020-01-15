//
// Created by Aletha Yellin on 03/12/2019.
//
#include "print_hex.h"

int     ft_print_x(t_spec *spec, va_list *args)
{
	char 		buffer[MAX_HEX_BUF_SIZE];

	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	get_hex(args, spec, buffer, 'a');
    return (print_digit_buf(buffer, spec, put_hex_prefix));
}

int     ft_print_X(t_spec *spec, va_list *args)
{
	char 		buffer[MAX_HEX_BUF_SIZE];

	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	get_hex(args, spec, buffer, 'A');
    return (print_digit_buf(buffer, spec, put_hex_prefix));
}