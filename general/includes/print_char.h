//
// Created by dan on 1/14/20.
//

#ifndef PRINTF_PRINT_CHAR_H
#define PRINTF_PRINT_CHAR_H


#include <stdarg.h>

#include "specificator.h"
#include "printf_constants.h"
#include "ft_putwchar.h"
#include  "print_str.h"

int		ft_print_c(t_spec* spec, va_list *args);

int     print_char(int c, t_spec *spec);

#endif //PRINTF_PRINT_CHAR_H
