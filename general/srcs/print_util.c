//
// Created by Aletha Yellin on 22/01/2020.
//

#include "print_util.h"

char	get_sign(char *digit, t_spec *spec)
{
	if (digit[0] == '-')
	{
		ft_strcpy(digit, digit + 1);
		return ('-');
	}
	else if (spec->flags['+'] == TRUE)
		return ('+');
	return ('\0');
}

int		print_sign(char sign)
{
	if (sign)
	{
		ft_putchar(sign);
		return (1);
	}
	return (0);
}

int		fill_width_field(int i, t_spec *spec)
{
	char	ch;
	int		len;
	int		diff;

	len = i;
	diff = get_diff(i, spec);
	ch = get_fill_ch(i, spec);
	while (i + diff < spec->width.value)
	{
		ft_putchar(ch);
		i++;
	}
	return (i - len);
}

int		fill_precision_field(char *buf, t_spec *spec)
{
	int diff;
	int i;
	int len;

	i = 0;
	len = ft_strlen(buf);
	diff = get_diff(len, spec);
	while (diff > 0)
	{
		ft_putchar('0');
		diff--;
		i++;
	}
	return (i);
}

