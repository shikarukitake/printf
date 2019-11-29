//
// Created by Aletha Yellin on 29/11/2019.
//

#include "common_print_funcs.h"

#define MAX_ULL_BUF_SIZE (sizeof(unsigned long long) * 8 + 1)

void fill_field(int i, t_spec *spec)
{
	char ch;

	if (ft_strchr(g_int_type_specs, spec->type))
		ch = ' ';
	else
		ch = (spec->flags['0'] == TRUE) ? ' ' : '0';
	while (i < spec->width.value)
	{
		ft_putchar(ch);
		i++;
	}
}

size_t print_signed_digit(va_list varg, t_spec *spec)
{
	char	buffer[MAX_ULL_BUF_SIZE];

	ft_bzero(buffer, MAX_ULL_BUF_SIZE);
	return (call_print_sd_func(varg, spec, buffer));

}