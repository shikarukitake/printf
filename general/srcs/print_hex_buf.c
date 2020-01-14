//
// Created by dan on 1/13/20.
//

#include "print_hex_buf.h"

static int put_hex_prefix(const char *buf, t_spec *spec, char *dest)
{
	if (spec->flags['#'] ==TRUE && buf[0] != '0')
	{
		if (spec->type == 'x')
		{
			if (dest)
				ft_strcpy(dest, HEX_SMALL_PREFIX);
			else
				ft_putstr(HEX_SMALL_PREFIX);
		}
		else if (spec->type == 'X')
		{
			if (dest)
				ft_strcpy(dest, HEX_BIG_PREFIX);
			else
				ft_putstr(HEX_BIG_PREFIX);
		}
		return (2);
	}
	return (0);
}

int	get_fill_ch(t_spec *spec)
{
	if(spec->flags['0'] == TRUE && spec->flags['-'] == FALSE)
		return '0';
	else
		return ' ';
}

int fill_hex_field(int i, t_spec *spec)
{
	char ch;
	int count;

	count = i;
	ch = get_fill_ch(spec);
	while (i < spec->width.value)
	{
		ft_putchar(ch);
		i++;
	}
	while (i < spec->precision.value)
	{
		ft_putchar('0');
		i++;
	}
	return (i - count);
}

static int prepare_buf(char *hex, t_spec *spec, char *hex_buf, int *was_prefix)
{
	ft_bzero(hex_buf, MAX_HEX_BUF_SIZE);
	if (hex[0] == '0' && spec->precision.is_dot == TRUE)
	{
		ft_bzero(hex, MAX_HEX_BUF_SIZE);
		*was_prefix = 0;
		return (0);
	}

	*was_prefix = put_hex_prefix(hex, spec, hex_buf);
	ft_strcat(hex_buf, hex);
	return (1);
}

int	print_hex_buf(char *hex, t_spec *spec)
{
	int i;
	char hex_buf[MAX_HEX_BUF_SIZE];
	int was_prefix;

	prepare_buf(hex, spec, hex_buf, &was_prefix);
	i = 0;
	if (spec->flags['-'] == TRUE)
	{
		i += print_buf(hex_buf);
		i += fill_hex_field(i, spec);
	}
	else
	{
		if (was_prefix && spec->flags['0'] == TRUE)
		{
			i += put_hex_prefix(hex, spec, NULL);
			i += fill_hex_field(ft_strlen(hex) + i, spec);
			i += print_buf(hex);
		}
		else
		{
			i += fill_hex_field(ft_strlen(hex_buf), spec);
			i += print_buf(hex_buf);
		}
	}
	return (i);
}