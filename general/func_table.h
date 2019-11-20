//
// Created by Aletha Yellin on 20/11/2019.
//

#ifndef PRINTF_FUNC_TABLE_H
#define PRINTF_FUNC_TABLE_H

void	call_func(const char *format, va_list args, int offset);

int		get_flag_id(char flag);

int		get_id(const char *spec);

#endif //PRINTF_FUNC_TABLE_H
