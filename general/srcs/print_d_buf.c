//
// Created by dan on 1/15/20.
//

#include "print_d_buf.h"

int put_sign_prefix(const char *buf, t_spec *spec, char *dest)
{
	if (spec->flags['+'] ==TRUE && buf[0] != '-')
	{
		if (spec->type == 'd')
		{
			if (dest)
				ft_strcpy(dest, "+");
			else
				ft_putstr("+");
		}
		return (1);
	}
	return (0);
}