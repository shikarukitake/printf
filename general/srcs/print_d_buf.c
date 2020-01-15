//
// Created by dan on 1/15/20.
//

#include "print_d_buf.h"

int is_need_wh(const char *buf, t_spec *spec)
{
	return (spec->flags[' '] == TRUE
			&& spec->flags['+'] == FALSE
			&& buf[0] != '-'
			&& spec->type == 'd');
}

int put_sign_prefix(const char *buf, t_spec *spec, char *dest)
{
	int i;

	i = 0;
	if (is_need_wh(buf, spec))
	{
		ft_putchar(' ');
		spec->width.value --;
		i++;
	}
	if (spec->flags['+'] == TRUE && buf[0] != '-')
	{
		if (spec->type == 'd')
		{
			if (dest)
				ft_strcpy(dest, "+");
			else
				ft_putstr("+");
		}
		i += 1;
	}
	return (i);
}