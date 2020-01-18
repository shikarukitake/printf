//
// Created by Aletha Yellin on 20/11/2019.
//

#include "print_basic.h"

int	ft_print_d(t_spec *spec, va_list *args)
{
	char 		buffer[MAX_LL_BUFF_SIZE];

	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	get_sd(args, spec, buffer);
	return (print_sd_buf(buffer, spec, put_sign_prefix));
}

int    ft_print_p(t_spec *spec, va_list *args)
{
    char        buffer[MAX_P_BUFF_SIZE];

    ft_bzero(buffer, MAX_P_BUFF_SIZE);
    get_p(args, spec, buffer);
    spec->flags['#'] = TRUE;
	return (print_d_buf(buffer, spec, put_hex_prefix));
}