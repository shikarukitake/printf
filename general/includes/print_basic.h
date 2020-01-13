//
// Created by Aletha Yellin on 20/11/2019.
//

#ifndef PRINTF_PRINT_BASIC_H
#define PRINTF_PRINT_BASIC_H


#include <stdarg.h>
#include <wchar.h>

#include "libft.h"
#include "printf_constatns.h"
#include "get_sd.h"
#include "get_p.h"
#include "print_buffer.h"
#include "print_ws.h"
#include "ft_putwchar.h"
#include "specificator.h"
#include "print_hex_buf.h"

int     ft_print_s(t_spec *spec, va_list *args);

int     ft_print_d(t_spec *spec, va_list *args);

int     ft_print_c(t_spec *spec, va_list *args);

int    ft_print_p(t_spec *spec, va_list *args);


#endif //PRINTF_PRINT_BASIC_H
