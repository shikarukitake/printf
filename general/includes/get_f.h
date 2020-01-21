//
// Created by Aletha Yellin on 13/12/2019.
//

#ifndef PRINTF_GET_F_H
#define PRINTF_GET_F_H

#include <stdarg.h>
#include "specificator.h"
#include "ft_float.h"
#include "get_float.h"

long double get_f(va_list *va_args, t_spec *spec, char *buffer);

#endif //PRINTF_GET_F_H
