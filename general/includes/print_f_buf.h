//
// Created by Aletha Yellin on 29/11/2019.
//

#ifndef PRINTF_PRINT_F_BUF_H
#define PRINTF_PRINT_F_BUF_H

#include "specificator.h"
#include "ft_float.h"
#include "libft.h"
#include "printf_constants.h"
#include "specificator.h"
#include "put_bch.h"
#include "print_digit_buf.h"
#include "print_str.h"


void    round_float(char *buf, int precision);

int     ft_put_float_buf(char *buf, t_spec *spec, t_float *f);

int     print_f_buf(char *f, t_spec *spec);

#endif //PRINTF_PRINT_F_BUF_H
