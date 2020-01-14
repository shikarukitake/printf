//
// Created by dan on 1/14/20.
//

#include "print_char.h"

static int fill_null_field(t_spec *spec)
{
	int count;
	int i;
	if (spec->precision.value == -1)
		i = 1;
	else
		i = spec->precision.value;
	count = i;
	while (i < spec->width.value)
	{
		ft_putchar(' ');
		i++;
	}
	return (i - count);
}

static int print_null_char(t_spec *spec)
{
	int i;

	i = 0;
	if (spec->flags['-'] == FALSE)
		i += fill_null_field(spec);
	i++;
	ft_putchar(0);
	if (spec->flags['-'] == TRUE)
		i += fill_null_field(spec);
	return (i);
}

static int print_char(int c, t_spec *spec)
{
	char buf[MAX_CHAR_BUF_SIZE];

	ft_bzero(buf, MAX_CHAR_BUF_SIZE);
	buf[0] = c;
	return print_str(buf, spec);
}

int		ft_print_c(t_spec* spec, va_list *args)
{
	char c;

	if (spec->size.id == -1)
	{
		c = va_arg(*args, int);
		if (c == 0)
			return print_null_char(spec);
		else
			return print_char(c, spec);
	}
	else if (spec->size.value[0] == 'L')
		ft_putwchar((wchar_t)va_arg(*args, wint_t));
	return (1);
}