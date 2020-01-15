//
// Created by dan on 1/14/20.
//

#ifndef PRINTF_PRINT_STR_H
#define PRINTF_PRINT_STR_H

#include "specificator.h"
#include <stdarg.h>
#include "print_ws.h"
#include "print_buffer.h"
#include "print_digit_buf.h"

int		ft_print_s(t_spec* spec, va_list *args);

int		print_str(char *str, t_spec *spec);

#endif //PRINTF_PRINT_STR_H
