//
// Created by Aletha Yellin on 29/11/2019.
//

#include "libft.h"
#include "printf_constatns.h"
#include "specificator.h"
#include "ft_float.h"

void fill_field(int i, t_spec *spec)
{
	char ch;

	if (ft_strchr(g_int_type_specs, spec->type))
		ch = ' ';
	else
		ch = (spec->flags['0'] == TRUE) ? ' ' : '0';
	while (i < spec->width.value)
	{
		ft_putchar(ch);
		i++;
	}
}

void	ft_put_sd_buf(char *buf, t_spec *spec)
{
	int i;
	int is_sign;

	i = 0;
	is_sign = (buf[0] != '-' && spec->flags['+'] == TRUE);
	if (spec->flags['-'] == TRUE)
	{
		i += ft_strlen(buf);
		if (is_sign)
		{
			ft_putchar('+');
			i++;
		}
		ft_putstr(buf);
		fill_field(i, spec);
	}
	else
	{
		fill_field(ft_strlen(buf) + is_sign, spec);
		if (is_sign)
			ft_putchar('+');
		ft_putstr(buf);
	}
}

void	ft_put_ud_buf(char *buf, t_spec *spec)
{
	int i;

	i = 0;
	if (spec->flags['-'] == TRUE)
	{
		i += ft_strlen(buf);
		ft_putstr(buf);
		fill_field(i, spec);
	}
	else
	{
		fill_field(ft_strlen(buf), spec);
		ft_putstr(buf);
	}
}

void	ft_put_hex_buf(char *buf, t_spec *spec)
{
	ft_putstr(HEX_SMALL_PREFIX);
	ft_put_sd_buf(buf, spec);
}

int is_need_zero(t_float *f)
{
	return (1);

}

void	ft_put_float_buf(char *buf, t_spec *spec, t_float *f)
{
	if (is_need_zero(f))
		ft_putchar('0');
	ft_put_sd_buf(buf, spec);
}