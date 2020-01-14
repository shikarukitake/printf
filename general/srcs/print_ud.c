//
// Created by Aletha Yellin on 03/12/2019.
//

#include "specificator.h"
#include "printf_constants.h"
#include "get_ud.h"
#include "libft.h"
#include "print_buffer.h"

int     ft_print_u(t_spec *spec, va_list *args)
{
	char 		buffer[MAX_LL_BUFF_SIZE];

	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	get_ud(args, spec, buffer);
    return (ft_put_ud_buf(buffer, spec));
}