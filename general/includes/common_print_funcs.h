//
// Created by Aletha Yellin on 29/11/2019.
//

#ifndef PRINTF_COMMON_PRINT_FUNCS_H
#define PRINTF_COMMON_PRINT_FUNCS_H

#include "ft_printf.h"


void	fill_field(int i, t_spec *spec);

size_t	print_signed_digit(va_list value, t_spec *spec);

#endif //PRINTF_COMMON_PRINT_FUNCS_H
