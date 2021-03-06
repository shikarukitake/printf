//
// Created by dan on 1/14/20.
//

#ifndef PRINTF_PRINT_STR_H
#define PRINTF_PRINT_STR_H

#include "specificator.h"
#include <stdarg.h>
#include "print_ws.h"
#include "print_f_buf.h"
#include "print_digit_buf.h"
#include "libft.h"

int		ft_print_s(t_spec* spec, va_list *args);

int		print_str(char *str, t_spec *spec);

#endif //PRINTF_PRINT_STR_H
