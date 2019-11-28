//
// Created by Aletha Yellin on 29/11/2019.
//

#include "ft_printf.h"

#define MAX_DIGIT_FUNC_TABLE 255

static int g_was_table_init = 0;

size_t 	(*g_print_sd_funcs[MAX_DIGIT_FUNC_TABLE])(va_list va_args, t_spec *spec, char *buffer);
//static const char *g_size_specs[MAX_SIZE_SPECS] = {"l", "hh", "h", "ll", "j", "z", "t", "L"};

int 	init_sd_func_table()
{
	if (g_was_table_init)
		return (0);
	g_was_table_init = 1;
	g_print_sd_funcs[0] = print_sl;
	g_print_sd_funcs[1] = print_shh;
	g_print_sd_funcs[2] = print_sh;
	g_print_sd_funcs[3] = print_sll;
	return (1);
}

size_t		call_sd_print_func(va_list va_args, t_spec *spec, char *buffer)
{
	int		id;
	size_t	result;

	init_sd_func_table();
	id = spec->size.id;
	if (id == -1)
		result = print_sd(va_args, spec, buffer);
	else
		result = g_print_sd_funcs[spec->size.id](va_args, spec, buffer);
	return (result);
}