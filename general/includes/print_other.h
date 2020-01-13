//
// Created by Aletha Yellin on 20/11/2019.
//

#ifndef PRINTF_PRINT_OTHER_H
#define PRINTF_PRINT_OTHER_H

#include "specificator.h"
#include <stdarg.h>
#include "libft.h"

int	ft_print_empty(t_spec *spec, va_list *args);

int	ft_print_percent(t_spec *spec, va_list *args);

int	ft_print_color(t_spec *spec, va_list *args);

#endif //PRINTF_PRINT_OTHER_H
