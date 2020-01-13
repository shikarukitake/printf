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

static	int put_x(char *hex)
{
	ft_putstr(hex);
	return (ft_strlen(hex));
}

int	print_hex_buf(char *hex, t_spec *spec)
{
	int i;
	char hex_buf[MAX_HEX_BUF_SIZE];

	if (hex[0] == '0' && spec->precision.is_dot == TRUE)
		return (0);
	ft_bzero(hex_buf, MAX_HEX_BUF_SIZE);
	put_hex_prefix(hex, spec, hex_buf);
	ft_strcat(hex_buf, hex);
	i = 0;
	if (spec->flags['-'] == TRUE)
	{
		i += put_x(hex_buf);
		i += fill_field(i, spec);
	}
	else
	{
		i += fill_field(ft_strlen(hex_buf), spec);
		i += put_x(hex_buf);
	}
	return (i);
}