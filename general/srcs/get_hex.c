//
// Created by Aletha Yellin on 29/11/2019.
//

#include "ft_printf.h"

void		get_hex(va_list va_args, t_spec *spec, char *buffer, char letter)
{
	t_convert_args	args;

	args = (t_convert_args) {0 , ft_itoa_base, ft_lltoa_base, 16, letter};
	get_general_digit(va_args, args, spec, buffer);
}