//
// Created by dan on 20.12.19.
//

#include "get_f.h"
#include "common_print.h"
#include "float_print.h"
#include "ft_float.h"
#include "printf_constatns.h"

void    ft_print_f(t_spec *spec, va_list *args)
{
	char	buffer[MAX_LD_BUF_SIZE];
	t_float	f;

	f = get_f(args, spec, buffer);
	ft_put_float_buf(buffer, spec, &f);
}