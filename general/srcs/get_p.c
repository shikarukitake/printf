//
// Created by Aletha Yellin on 11/12/2019.
//

#include "ft_printf.h"

void		get_p(va_list *va_args, t_spec *spec, char *buffer)
{
    t_conv	conv;

    conv = (t_conv) {0 , 16, 'a'};
    get_general_ptr(va_args, &conv, spec, buffer);
}