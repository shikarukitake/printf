//
// Created by Aletha Yellin on 22/01/2020.
//

#include "print_sd_buf.h"

int		fill_sign_width_field(int i, t_spec *spec, char sign)
{
	char	ch;
	int		len;
	int		diff;

	len = i;
	diff = get_diff(i, spec);
	ch = get_fill_ch(i + (sign > 0), spec);
	while (i + diff + (sign > 0) < spec->width.value)
	{
		ft_putchar(ch);
		i++;
	}
	return (i - len);
}

int		print_sd_buf(char *digit, t_spec *spec)
{
	int		i;
	char	sign;

	i = 0;
	if (is_null_case(digit, spec))
		ft_bzero(digit, MAX_HEX_BUF_SIZE);
	if (is_need_wh(digit, spec))
	{
		ft_putchar(' ');
		spec->width.value--;
	}
	sign = get_sign(digit, spec);
	if (spec->flags['-'] == TRUE)
	{
		i += print_sign(sign);
		i += fill_precision_field(digit, spec);
		i += print_buf(digit);
		i += fill_width_field(i, spec);
	}
	else
	{
		if (get_fill_ch((int)ft_strlen(digit) + (sign > 0), spec) == ' ')
		{
			i += fill_sign_width_field(ft_strlen(digit), spec, sign);
			i += print_sign(sign);
		}
		else
		{
			i += print_sign(sign);
			i += fill_sign_width_field(ft_strlen(digit), spec, sign);
		}
		i += fill_precision_field(digit, spec);
		i += print_buf(digit);
	}
	if (is_need_wh(digit, spec) && (sign <= 0))
		i++;
	return (i);
}