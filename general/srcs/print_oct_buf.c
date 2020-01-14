//
// Created by dan on 1/14/20.
//

#include "print_oct_buf.h"

static int put_oct_prefix(const char *buf, t_spec *spec, char *dest)
{
	if (spec->flags['#'] ==TRUE && buf[0] != '0')
	{
		if (spec->type == 'o')
		{
			if (dest)
				ft_strcpy(dest, OCT_PREFIX);
			else
				ft_putstr(OCT_PREFIX);
		}
		return (2);
	}
	return (0);
}

int prepare_buf(char *oct, t_spec *spec, char *oct_buf, int *was_prefix)
{
	ft_bzero(oct_buf, MAX_HEX_BUF_SIZE);
	if (oct[0] == '0' && spec->precision.is_dot == TRUE)
	{
		ft_bzero(oct, MAX_HEX_BUF_SIZE);
		*was_prefix = 0;
		return (0);
	}
	*was_prefix = put_oct_prefix(oct, spec, oct_buf);
	ft_strcat(oct_buf, oct);
	return (1);
}

int get_diff(int buf_len, t_spec *spec)
{
	if (spec->precision.value == -1)
		return (0);
	else if (spec->precision.value < buf_len)
		return (0);
	return (spec->precision.value - buf_len);
}


int fill_oct_field_width(int i, t_spec *spec)
{
	char	ch;
	int		len;
	int		diff;

	len = i;
	diff = get_diff(i, spec);
	ch = get_fill_ch(spec);
	while (i + diff < spec->width.value)
	{
		ft_putchar(ch);
		i++;
	}
	return (i - len);
}

int fill_oct_precision(char *buf, t_spec *spec)
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

int	print_oct_buf(char *oct, t_spec *spec)
{
	int 	i;
	char	oct_buf[MAX_HEX_BUF_SIZE];
	int		was_prefix;

	prepare_buf(oct, spec, oct_buf, &was_prefix);
	i = 0;
	if (spec->flags['-'] == TRUE)
	{
		i += fill_oct_precision(oct_buf, spec);
		i += print_buf(oct_buf);
		i += fill_oct_field_width(i, spec);
	}
	else
	{
		if (was_prefix && spec->flags['0'] == TRUE)
		{
			i += put_oct_prefix(oct, spec, NULL);
			i += fill_oct_field_width(ft_strlen(oct) + i, spec);
			i += fill_oct_precision(oct, spec);
			i += print_buf(oct);
		}
		else
		{
			i += fill_oct_field_width(ft_strlen(oct_buf), spec);
			i += fill_oct_precision(oct_buf, spec);
			i += print_buf(oct_buf);
		}
	}
	return (i);
}