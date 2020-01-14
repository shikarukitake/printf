//
// Created by Aletha Yellin on 29/11/2019.
//

#ifndef PRINTF_PRINT_BUFFER_H
#define PRINTF_PRINT_BUFFER_H

#include "specificator.h"
#include "ft_float.h"
#include "libft.h"
#include "printf_constants.h"
#include "specificator.h"

int   	fill_field(int i, t_spec *spec);

int     ft_put_sd_buf(char *buf, t_spec *spec);

int     ft_put_ud_buf(char *buf, t_spec *spec);

int     ft_put_float_buf(char *buf, t_spec *spec, t_float *f);

size_t	print_buf(const char *buf);

#endif //PRINTF_PRINT_BUFFER_H
