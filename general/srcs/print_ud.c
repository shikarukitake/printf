//
// Created by Aletha Yellin on 03/12/2019.
//

#include "print_ud.h"

int     ft_print_u(t_spec *spec, va_list *args)
{
	char 		buffer[MAX_LL_BUFF_SIZE];

	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	get_ud(args, spec, buffer);
    return (print_digit_buf(buffer, spec, put_sign_prefix));
}