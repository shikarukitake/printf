//
// Created by Aletha Yellin on 03/12/2019.
//

#include "ft_printf.h"

void	ft_print_o(t_spec *spec, va_list args)
{
	char 		buffer[MAX_LL_BUFF_SIZE];

	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	get_oct(args, spec, buffer, 'a');
	ft_put_sd_buf(buffer, spec);
}
