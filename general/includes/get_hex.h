//
// Created by Aletha Yellin on 29/11/2019.
//

#ifndef PRINTF_GET_HEX_H
#define PRINTF_GET_HEX_H

#include <stdarg.h>
#include "specificator.h"
#include "convert.h"
#include "get_digit.h"

void		get_hex(va_list *va_args, t_spec *spec, char *buffer, char letter);

#endif //PRINTF_GET_HEX_H
