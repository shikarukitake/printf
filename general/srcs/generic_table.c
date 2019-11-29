//
// Created by Aletha Yellin on 29/11/2019.
//

#include "ft_printf.h"

#define MAX_HEX_FUNC_TABLE 255

static int g_was_table_init = 0;

t_to_str 	g_hex_convert[MAX_HEX_FUNC_TABLE];
//static const char *g_size_specs[MAX_SIZE_SPECS] = {"l", "hh", "h", "ll", "j", "z", "t", "L"};

void	init_hex_to_str(t_to_str s, t_convert_args args, t_to_str_func f)
{
	s.args = args;
	s.f = f;
}

int 	init_get_hex_func_table()
{
	if (g_was_table_init)
		return (0);
	g_was_table_init = 1;
	t_convert_args long_args = {0,   NULL, ft_lltoa_base, 16, 'a'};
	t_convert_args int_args  = {0, ft_itoa_base, NULL, 16, 'a'};
	init_hex_to_str(g_hex_convert[0], long_args, get_hex);
	init_hex_to_str(g_hex_convert[1], int_args, get_hex);
	init_hex_to_str(g_hex_convert[2], long_args, get_hex);
	init_hex_to_str(g_hex_convert[3], long_args, get_hex);
	return (1);
}

size_t		call_get_hex_func(va_list va_args, t_spec *spec, char *buffer)
{
	int				id;
	size_t			result;
	t_to_str_func	f;
	t_convert_args		convert;

	init_get_hex_func_table();
	id = spec->size.id;
	if (id == -1)
		result = get_hex(va_args, spec, buffer);
	else
	{
		convert = g_get_hex_funcs[spec->size.id];
		convert.func(va_args, convert, buffer);
	}
	return (result);
}