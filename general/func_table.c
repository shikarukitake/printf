//
// Created by Aletha Yellin on 20/11/2019.
//

#include "ft_printf.h"

void 	(*g_func_table[4])(const char *, va_list) = {
		ft_putempty,
		ft_putstr_args,
		ft_putnum_args,
		ft_putpercent
};

void	call_func(const char *format, va_list args, int offset)
{
	g_func_table[get_id(format + offset + 1)](format + offset + 1, args);
}

int 	get_flag_id(char flag)
{
	if (flag == 's')
		return (FT_PRINTF_STR);
	if (flag == 'd')
		return (FT_PRINTF_D);
	if (flag == '%')
		return (FT_PRINTF_PERCENT);
	else
		return (FT_PRINTF_EMPTY);
}

int	get_id(const char *spec)
{
	t_pair *p;

	if((p = ft_strfind(spec, g_specificators)))
		return (get_flag_id(spec[p->x]));
	return (0);
}