//
// Created by Aletha Yellin on 23/01/2020.
//

#ifndef PRINTF_FLOAT_UTIL_H
#define PRINTF_FLOAT_UTIL_H

#include "specificator.h"

int			get_float_precision(t_spec *spec);

char		get_float_fill_ch(t_spec *spec);

int			is_special_value(char *buf);

int			is_float_null_case(char *f, t_spec *spec);

#endif //PRINTF_FLOAT_UTIL_H
