//
// Created by Aletha Yellin on 13/12/2019.
//

#ifndef PRINTF_GET_FLOAT_H
#define PRINTF_GET_FLOAT_H

# include <stdarg.h>
# include "specificator.h"
# include "convert.h"
#include "ft_float.h"
#include "float_convert.h"

t_float   get_general_float(va_list *va_args, t_conv *conv, t_spec *spec, char *buffer);

#endif //PRINTF_GET_FLOAT_H
