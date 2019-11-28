//
// Created by Aletha Yellin on 29/11/2019.
//

#include "common_print_funcs.h"

void fill_field(int i, t_spec *spec)
{
	char ch;

	ch = (spec->flags['0'] == TRUE) ? ' ' : '0';
	while (i < spec->width.value)
	{
		ft_putchar(ch);
		i++;
	}
}

int print_signed_int_value(long long value, t_spec *spec)
{
	if (spec->flags['+'] == TRUE && value > 0)
		ft_putchar('+');
	if (!spec->size.value[0])
		ft_putnbr((int)value);
	else if (spec->size.value[0] == 'h' && spec->size.value[1] == 'h')
		ft_putnbr((signed char)value);
	else if (spec->size.value[0] == 'h')
		ft_putnbr((signed short int)value);
	else if (spec->size.value[0] == 'l' && spec->size.value[1] == 'l')
		ft_putll(value);
	else if (spec->size.value[0] == 'l')
		ft_putll((long)value);

	return (0);
}