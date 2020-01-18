//
// Created by dan on 1/13/20.
//

#include "print_hex_buf.h"

void    put_or_copy(char *dest, const char *prefix)
{
    if (dest)
        ft_strcpy(dest, prefix);
    else
        ft_putstr(prefix);
}

int     put_hex_prefix(const char *buf, t_spec *spec, char *dest)
{
    if (spec->type == 'p')
    {
        put_or_copy(dest, HEX_SMALL_PREFIX);
        return (2);
    }
	if (spec->flags['#'] == TRUE && buf[0] != '0')
	{
		if (spec->type == 'x')
			put_or_copy(dest, HEX_SMALL_PREFIX);
		else if (spec->type == 'X')
		    put_or_copy(dest, HEX_BIG_PREFIX);
		return (2);
	}
	return (0);
}