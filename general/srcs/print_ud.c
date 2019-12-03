//
// Created by Aletha Yellin on 03/12/2019.
//

#include "specificator.h"
#include "printf_constatns.h"
#include "get_ud.h"
#include "libft.h"
#include "common_print.h"

void	ft_print_u(t_spec *spec, va_list args)
{
	char 		buffer[MAX_LL_BUFF_SIZE];

	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	get_ud(args, spec, buffer);
	ft_put_ud_buf(buffer, spec);
}