//
// Created by Aletha Yellin on 22/01/2020.
//

#include "spec_util.h"

int		get_diff(int buf_len, t_spec *spec)
{
	if (spec->precision.value == -1 || spec->precision.value < buf_len)
		return (0);
	return (spec->precision.value - buf_len);
}

char	get_fill_ch(int len, t_spec *spec)
{
	if (spec->flags['0'] == TRUE && spec->precision.value < spec->width.value && spec->precision.value != -1)
		return (' ');
	if (spec->flags['0'] == TRUE && spec->precision.value < len && spec->precision.value != -1)
		return (' ');
	if (spec->flags['0'] == TRUE && spec->flags['-'] == FALSE)
		return ('0');
	else
		return (' ');
}

int		is_null_case(const char *digit, t_spec *spec)
{
	int b;

	b = (digit[0] == '0' && spec->precision.is_dot == TRUE
		 && (spec->precision.value <= 0));
	if (spec->type == 'x' || spec->type == 'X' || spec->type == 'p')
		return (b);
	else
		return (b && spec->flags['#'] == FALSE);
}