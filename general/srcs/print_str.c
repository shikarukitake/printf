//
// Created by dan on 1/14/20.
//

#include "print_str.h"

int fill_str_field(int i, t_spec *spec)
{
	int count;

	count = i;
	while (i < spec->width.value)
	{
		ft_putchar(' ');
		i++;
	}
	return (i - count);
}


int		print_str(char *str, t_spec *spec)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (spec->precision.value == -1)
	{
		i += fill_str_field(ft_strlen(str), spec);
		ft_putstr(str);
		return (ft_strlen(str) + i);
	}
	else
	{
		i += fill_str_field(spec->precision.value, spec);
		while (j < spec->precision.value && j < (int)ft_strlen(str))
		{
			ft_putchar(str[j++]);
			i++;
		}
		return (i);
	}
}

int		ft_print_s(t_spec* spec, va_list *args) {
	char *tmp;

	if (spec->size.id == -1)
	{
		tmp = va_arg(*args, char *);
		return (print_str(tmp, spec));
	} else if (spec->size.value[0] == 'l')
		return (ft_print_ws(spec, args));
	return (0);
}