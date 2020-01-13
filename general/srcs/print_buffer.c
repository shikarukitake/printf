//
// Created by Aletha Yellin on 29/11/2019.
//

#include "print_buffer.h"

int is_wh(t_spec *spec)
{
	return	(!ft_strchr(FT_PRINTF_INT_TYPES, spec->type)
			|| spec->flags['-'] == TRUE
			|| ((spec->width.value != 0) && spec->width.value > spec->precision.value));
}

int fill_field(int i, t_spec *spec)
{
	char ch;
	int count;

	count = i;
	if (is_wh(spec))
		ch = ' ';
	else
		ch = (spec->flags['0'] == TRUE) ? ' ' : '0';
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

int		ft_put_sd_buf(char *buf, t_spec *spec)
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
		i += fill_field(i, spec);
	}
	else
	{
		i += fill_field(ft_strlen(buf) + is_sign, spec);
		if (is_sign)
		{
            ft_putchar('+');
            i++;
        }
		ft_putstr(buf);
		i+= ft_strlen(buf);
	}
	return (i); // Maybe wrong
}

int	ft_put_ud_buf(char *buf, t_spec *spec)
{
	int i;

	i = 0;
	if (spec->flags['-'] == TRUE)
	{
		i += ft_strlen(buf);
		ft_putstr(buf);
		i += fill_field(i, spec);
	}
	else
	{
		i += fill_field(ft_strlen(buf), spec);
		ft_putstr(buf);
	}
	return (i + ft_strlen(buf)); //Wrong
}



int     ft_put_float_buf(char *buf, t_spec *spec, t_float *f)
{
    int i;
    int float_nums;

	i = 0;
    ((void)f);
	float_nums = -1;
	while (buf[i] != '.')
    {
	    ft_putchar(buf[i]);
	    i++;
    }
	while (buf[i])
    {
		if (spec->precision.value != -1 && float_nums == spec->precision.value)
				break;
	    ft_putchar(buf[i]);
	    float_nums++;
	    i++;
    }
	if (spec->precision.value == -1 && float_nums < 6)
    {
	    while (float_nums < 6)
	    {
            ft_putchar('0');
            float_nums++;
        }
    }
    return (i + float_nums);
}