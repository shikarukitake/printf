//
// Created by Aletha Yellin on 29/11/2019.
//

#include "print_buffer.h"

void change_first_digits(char *buf)
{
    char tmp[MAX_FLOAT_BUFF_SIZE];

    ft_strcpy(tmp , buf);
    if (tmp[0] != '-')
    {
        ft_strcpy(buf, "10");
        ft_strcat(buf, tmp + 1);
    }
    else
    {
        ft_strcpy(buf, "-10");
        ft_strcat(buf, tmp + 2);
    }
}

void    round_int_part(char *buf)
{
    int i;

    i = ft_strchri(buf, '.');
    if (buf[i - 1] < '9')
        buf[i - 1] += 1;
    else
    {
        buf[i - 1] = '0';
        i--;
        while (i > 0 && buf[i] == '9') {
            buf[i] = '0';
            i--;
        }
        if (i == 0 && buf[i + 1] == '0')
            change_first_digits(buf);
    }
}

void    round_float(char *buf, int precision)
{
    int dot;
    int i;
    int last;

    dot = ft_strchri(buf, '.');
    i = dot + precision + 1;
    buf[i + 1] = '\0';
    last = i;
    if (buf[i] > '4' && buf[i - 1] != '.' )// && (buf[i - 1] - '0') % 2 != 0)
    {
        i--;
        if (buf[i] != '9')
            buf[i] += 1;
        else if (buf[i] == '9')
        {
            buf[i--] = '0';
            while (buf[i] == '9')
            {
                buf[i] = '0';
                i--;
            }
            if (buf[i] != '.')
                buf[i] += 1;
            else
                round_int_part(buf);
        }
    }
    buf[last] = '\0';
}


int     ft_put_float_buf(char *buf, t_spec *spec, t_float *f)
{
    int i;
    int float_nums;

	i = 0;
    ((void)f);
    round_float(buf, spec->precision.value == -1 ? 6 : spec->precision.value);
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

