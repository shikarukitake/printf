//
// Created by Aletha Yellin on 20/11/2019.
//

#include "ft_printf.h"
#include <stdlib.h>

#define MAX_TYPE_FUNC_TABLE 255

void 	(*g_type_func_table[MAX_TYPE_FUNC_TABLE])(const char *, va_list);

int 	init_func_table()
{
	g_type_func_table['s'] = ft_print_s;
	g_type_func_table['d'] = ft_print_d;
	g_type_func_table['0'] = ft_print_empty;
	g_type_func_table['%'] = ft_print_percent;
}

int		get_func_id(const char *fmt)
{
	t_pair	*p;
	int		func_id;

	if((p = ft_strfind(fmt, g_type_specs)))
	{
		func_id = get_type_id_in_table(fmt[p->x]);
		free(p);
		return (func_id);
	}
	return (0);
}
void	call_print_func(const char *format, va_list args, int offset)
{
	g_type_func_table[get_func_id(format + offset + 1)](format + offset + 1, args);
}



