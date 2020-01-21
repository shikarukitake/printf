//
// Created by Aletha Yellin on 21/01/2020.
//

#include "print_e_buf.h"


int		print_e_buf(char *e, t_spec *spec, char a)
{
	print_f_buf(e, spec);
	ft_putchar(a);
	return (0);
}