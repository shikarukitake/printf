//
// Created by Aletha Yellin on 03/12/2019.
//

#include "specificator.h"
#include "printf_constatns.h"
#include "get_hex.h"
#include "common_print.h"
#include "libft.h"

int     ft_print_x(t_spec *spec, va_list *args)
{
	char 		buffer[MAX_LL_BUFF_SIZE];

	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	get_hex(args, spec, buffer, 'a');
    return (ft_put_sd_buf(buffer, spec));
}

int     ft_print_X(t_spec *spec, va_list *args)
{
	char 		buffer[MAX_LL_BUFF_SIZE];

	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	get_hex(args, spec, buffer, 'A');
    return (ft_put_sd_buf(buffer, spec));
}