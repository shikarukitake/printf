//
// Created by Aletha Yellin on 22/11/2019.
//

#include "ft_printf.h"

int		get_signed_digit(va_list args, t_spec *spec, char *buffer)
{
	return (call_get_sd_func(args, spec, buffer));
}

int 	get_hex_digit(va_list args, t_spec *spec, char *buffer)
{
	return (call_get_hex_func(args, spec, buffer));
}