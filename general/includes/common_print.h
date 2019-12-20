//
// Created by Aletha Yellin on 29/11/2019.
//

#ifndef PRINTF_COMMON_PRINT_H
#define PRINTF_COMMON_PRINT_H

#include "specificator.h"
#include "ft_float.h"

void	fill_field(int i, t_spec *spec);

void	ft_put_sd_buf(char *buf, t_spec *spec);

void	ft_put_ud_buf(char *buf, t_spec *spec);

void	ft_put_hex_buf(char *buf, t_spec *spec);

void	ft_put_float_buf(char *buf, t_spec *spec, t_float *f);

#endif //PRINTF_COMMON_PRINT_H
