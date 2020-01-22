//
// Created by dan on 1/14/20.
//

#include "print_oct_buf.h"

int		is_oct_prefix(t_spec *spec)
{
	return (spec->type == 'o' && spec->flags['#'] == TRUE);
}

int put_oct_prefix(const char *buf, t_spec *spec, char *dest)
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
		return (1);
	}
	return (0);
}
