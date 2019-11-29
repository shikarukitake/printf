//
// Created by Aletha Yellin on 29/11/2019.
//

#include "ft_printf.h"

#define MAX_DIGIT_FUNC_TABLE 255

static int g_was_table_init = 0;

size_t 	(*g_get_hex_funcs[MAX_DIGIT_FUNC_TABLE])(va_list va_args, t_spec *spec, char *buffer);
//static const char *g_size_specs[MAX_SIZE_SPECS] = {"l", "hh", "h", "ll", "j", "z", "t", "L"};

int 	init_get_hex_func_table()
{
	if (g_was_table_init)
		return (0);
	g_was_table_init = 1;
	g_get_hex_funcs[0] = get_hex_l;
	g_get_hex_funcs[1] = get_hex_hh;
	g_get_hex_funcs[2] = get_hex_h;
	g_get_hex_funcs[3] = get_hex_ll;
	return (1);
}

size_t		call_get_hex_func(va_list va_args, t_spec *spec, char *buffer)
{
	int		id;
	size_t	result;

	init_get_hex_func_table();
	id = spec->size.id;
	if (id == -1)
		result = get_hex(va_args, spec, buffer);
	else
		result = g_get_hex_funcs[spec->size.id](va_args, spec, buffer);
	return (result);
}