//
// Created by Aletha Yellin on 03/12/2019.
//

#ifndef PRINTF_GET_OCT_H
#define PRINTF_GET_OCT_H


#include <stdarg.h>
#include "convert.h"
#include "get_digit.h"
#include "specificator.h"

void	get_oct(va_list *vargs, t_spec *spec, char *buffer, char letter);

#endif //PRINTF_GET_OCT_H
