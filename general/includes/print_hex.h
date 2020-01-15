//
// Created by Aletha Yellin on 03/12/2019.
//

#ifndef PRINTF_PRINT_HEX_H
#define PRINTF_PRINT_HEX_H

#include"specificator.h"
#include <stdarg.h>
#include "printf_constants.h"
#include "get_hex.h"
#include "print_hex_buf.h"
#include "libft.h"
#include "print_digit_buf.h"

int	ft_print_x(t_spec *spec, va_list *args);

int	ft_print_X(t_spec *spec, va_list *args);

#endif //PRINTF_PRINT_HEX_H
