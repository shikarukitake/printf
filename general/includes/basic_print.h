//
// Created by Aletha Yellin on 20/11/2019.
//

#ifndef PRINTF_BASIC_PRINT_H
#define PRINTF_BASIC_PRINT_H

#include "specificator.h"

int	ft_print_s(t_spec *spec, va_list *args);

int	ft_print_d(t_spec *spec, va_list *args);

int	ft_print_c(t_spec *spec, va_list *args);

int    ft_print_p(t_spec *spec, va_list *args);

#endif //PRINTF_BASIC_PRINT_H
