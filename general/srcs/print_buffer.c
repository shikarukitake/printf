//
// Created by Aletha Yellin on 29/11/2019.
//

#include "print_buffer.h"

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

