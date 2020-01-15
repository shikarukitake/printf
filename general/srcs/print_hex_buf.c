//
// Created by dan on 1/13/20.
//

#include "print_hex_buf.h"

int put_hex_prefix(const char *buf, t_spec *spec, char *dest)
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