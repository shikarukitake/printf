//
// Created by Aletha Yellin on 29/11/2019.
//

#include "get_hex.h"

void		get_hex(va_list *va_args, t_spec *spec, char *buffer, char letter)
{
	t_conv	conv;

    conv = (t_conv) {0 , 16, letter};
	get_general_ud(va_args, &conv, spec, buffer);
}