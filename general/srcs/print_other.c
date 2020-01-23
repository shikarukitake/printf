//
// Created by Aletha Yellin on 20/11/2019.
//

#include "print_other.h"

int ft_print_empty(t_spec *spec, va_list *args)
{
	((void)spec);
	((void)args);
	return (0);
}

char get_percent_fill_ch(t_spec *spec)
{
	if (spec->flags['0'] == TRUE && spec->flags['-'] == FALSE)
		return '0';
	else
		return ' ';
}

int ft_print_percent(t_spec *spec, va_list *args)
{
	int i;
	char ch;

	i = 0;
	ch = get_percent_fill_ch(spec);
	(void)(args);
	if (spec->flags['-'] == TRUE)
	{
		ft_putchar('%');
		i++;
		while (i < spec->width.value)
		{
			ft_putchar(ch);
			i++;
		}
	}
	else
	{
		while (i < spec->width.value - 1)
		{
			ft_putchar(ch);
			i++;
		}
		ft_putchar('%');
		i++;
	}
	return (i);
}

int ft_print_color(t_spec *spec, va_list *args)
{
	((void)spec);
	((void)args);
	return (6);
}