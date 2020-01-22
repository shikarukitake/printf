//
// Created by Aletha Yellin on 22/01/2020.
//

#ifndef PRINTF_SPEC_UTIL_H
#define PRINTF_SPEC_UTIL_H

#include "specificator.h"
#include "libft.h"

char	get_fill_ch(int len, t_spec *spec);

int		get_diff(int buf_len, t_spec *spec);

int		is_null_case(const char *digit, t_spec *spec);

#endif //PRINTF_SPEC_UTIL_H
