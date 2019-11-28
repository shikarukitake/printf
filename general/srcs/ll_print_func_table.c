//
// Created by Aletha Yellin on 29/11/2019.
//

#include "ft_printf.h"

#define MAX_LL_FUNC_TABLE 255

static int g_was_table_init = 0;

void 	(*g_ll_print_func_table[MAX_LL_FUNC_TABLE])(long long value);


int 	init_size_func_table()
{
	if (g_was_table_init)
		return (0);
	g_was_table_init = 1;
	g_ll_print_func_table[0] = ft_putll;

	return (1);
}

void call_ll_print_func(int id, long long value)
{
	init_size_func_table();
	if (id != -1)
		g_ll_print_func_table[id](value);
}