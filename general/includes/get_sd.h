//
// Created by Aletha Yellin on 29/11/2019.
//

#ifndef PRINTF_GET_SD_H
#define PRINTF_GET_SD_H

#include <stdarg.h>
#include "specificator.h"
#include "convert.h"
#include "get_digit.h"

void		get_sd(va_list *va_args, t_spec *spec, char *buffer);

#endif //PRINTF_GET_SD_H
