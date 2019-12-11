//
// Created by Aletha Yellin on 29/11/2019.
//

#ifndef PRINTF_GET_DIGIT_H
#define PRINTF_GET_DIGIT_H

#include "get_hex.h"
#include <stdarg.h>
#include "specificator.h"

void	get_general_d(va_list vargs, t_conv args, t_spec *spec, char *buf);

void	get_general_ud(va_list vargs, t_conv args, t_spec *spec, char *buf);

void	get_general_ptr(va_list vargs, t_conv args, t_spec *spec, char *buf);

#endif //PRINTF_GET_DIGIT_H
