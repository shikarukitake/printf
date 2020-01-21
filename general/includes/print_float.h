//
// Created by dan on 20.12.19.
//

#ifndef PRINTF_PRINT_FLOAT_H
#define PRINTF_PRINT_FLOAT_H

#include "specificator.h"
#include "stdarg.h"
#include "get_f.h"
#include "print_f_buf.h"
#include "print_float.h"
#include "ft_float.h"
#include "printf_constants.h"
#include "libft.h"
#include "print_e_buf.h"

int    ft_print_f(t_spec *spec, va_list *args);

int    ft_print_e(t_spec *spec, va_list *args);

int    ft_print_E(t_spec *spec, va_list *args);

#endif //PRINTF_PRINT_FLOAT_H
