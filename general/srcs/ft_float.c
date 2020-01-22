//
// Created by dan on 20.12.19.
//

#include "ft_float.h"
#include "special_float_values.h"

void transform_long_result(char *buf, char *new_buf, int n)
{
	int i;
	int j;
	int last;

	last = n - 1;
	while (last > 0 && buf[last] == 0)
		last --;
	i = last;
	j = 0;
	while (i >= 0)
	{
		new_buf[j ++] = (char) (buf[i] + '0');
		i --;
	}
	new_buf[j] = '\0';
}

void get_long_int_part(unsigned long m, unsigned e, char *buf)
{
	char			int_part[MAX_FLOAT_BUFF_SIZE];
	char			result[MAX_FLOAT_BUFF_SIZE];
	unsigned long	mask;
	int				was_mult;
	int				n;

	n = MAX_FLOAT_BUFF_SIZE;
	ft_memset(result, 0, MAX_FLOAT_BUFF_SIZE);
	was_mult = 0;
	int_part[0] = 1;
	mask = 1u;

	mask <<= 63lu;
	e ++;
	while (e)
	{
		if ((mask & m) > 0)
		{
			if (! was_mult)
			{
				ft_memset(int_part, 0, MAX_FLOAT_BUFF_SIZE);
				int_part[0] = 1;
				multiply_by_2(int_part, n, e - 1);
				was_mult = 1;
			}
			long_sum(int_part, result, n, 0);
		}
		if (was_mult)
			rev_divide_by_2(int_part, n);
		mask >>= 1u;
		e --;
	}
	transform_long_result(result, buf, n);
}

void	make_float_buffer(long double ld, char *buf, char *i_part, char *f_part)
{
	if (ld < 0)
		buf[0] = '-';
	ft_strcat(buf, i_part);
	ft_strcat(buf, ".");
	ft_strcat(buf, f_part);
	free(i_part);
	free(f_part);
}

void ft_dtoa(long double ld, char *buffer)
{
	char	*int_part_buf;
	char	*float_part_buf;
	int		less_than_one;
	t_ldc	ldc;

	ldc = (t_ldc) {.ld = ld};
	if (is_reserved_value(ldc, ld, buffer))
		return;
	if (ldc.parts.e >= EXP_SHIFT)
	{
		ldc.parts.e = ldc.parts.e - EXP_SHIFT;
		int_part_buf = ft_memalloc(MAX_FLOAT_BUFF_SIZE);
		get_long_int_part(ldc.parts.m, ldc.parts.e, int_part_buf);
		less_than_one = 1;
	} else
	{
		ldc.parts.e = EXP_SHIFT - ldc.parts.e;
		int_part_buf = ft_strdup("0");
		less_than_one = 0;
	}
	if (ldc.parts.e < 63u || less_than_one == 0)
	{
		float_part_buf = ft_memalloc(MAX_FLOAT_BUFF_SIZE);
		get_float_part(ldc.parts.m, ldc.parts.e, float_part_buf, less_than_one);
	}
	else
		float_part_buf = ft_strdup("0");
	make_float_buffer(ld, buffer, int_part_buf, float_part_buf);
}
