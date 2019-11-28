//
// Created by Aletha Yellin on 29/11/2019.
//

#ifndef PRINTF_LL_PRINT_FUNC_TABLE_H
#define PRINTF_LL_PRINT_FUNC_TABLE_H

#include "ft_printf.h"

void	call_size_print_func(const char *size);

int 	init_func_table();

int		get_type_func_id(const char *size);

#endif //PRINTF_LL_PRINT_FUNC_TABLE_H
