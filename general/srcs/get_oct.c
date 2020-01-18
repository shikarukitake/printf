//
// Created by Aletha Yellin on 03/12/2019.
//

#include "get_oct.h"


void	get_oct(va_list *vargs, t_spec *spec, char *buffer, char letter)
{
	t_conv	conv;

    conv = (t_conv) {0 , 8, letter};
	get_general_ud(vargs, &conv, spec, buffer);
}