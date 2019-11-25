//
// Created by Aletha Yellin on 20/11/2019.
//

#include "ft_printf.h"
#include <stdlib.h>

void 	(*g_func_table[4])(const char *, va_list) = {
		ft_putempty,
		ft_print_str,
		ft_print_num,
		ft_putpercent
};

int 	get_type_id_in_table(char flag)
{
	if (flag == 's')
		return (FT_PRINTF_STR);
	if (flag == 'd')
		return (FT_PRINTF_DIGIT);
	if (flag == '%')
		return (FT_PRINTF_PERCENT);
	else
		return (FT_PRINTF_EMPTY);
}

int	get_func_id(const char *fmt)
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
	g_func_table[get_func_id(format + offset + 1)](format + offset + 1, args);
}



