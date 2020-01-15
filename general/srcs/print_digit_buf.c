//
// Created by dan on 1/15/20.
//

#include "print_digit_buf.h"

int is_null_case(const char *digit, t_spec *spec)
{
	int b;

	b = (digit[0] == '0' && spec->precision.is_dot == TRUE);
	if (spec->type == 'x' || spec->type == 'X')
		return (b);
	else
		return (b && spec->flags['#'] == FALSE);
}


int prepare_buf(char *digit, t_spec *spec, char *dig_buf, t_put_prefix p)
{
	int was_prefix;

	ft_bzero(dig_buf, MAX_HEX_BUF_SIZE);
	if (is_null_case(digit, spec))
	{
		ft_bzero(digit, MAX_HEX_BUF_SIZE);
		return (0);
	}
	was_prefix = p(digit, spec, dig_buf);
	ft_strcat(dig_buf, digit);
	return (was_prefix);
}

int get_diff(int buf_len, t_spec *spec)
{
	if (spec->precision.value == -1)
		return (0);
	else if (spec->precision.value < buf_len)
		return (0);
	return (spec->precision.value - buf_len);
}

int	get_fill_ch(t_spec *spec)
{
	if(spec->flags['0'] == TRUE && spec->flags['-'] == FALSE)
		return '0';
	else
		return ' ';
}

int fill_width_field(int i, t_spec *spec)
{
	char	ch;
	int		len;
	int		diff;

	len = i;
	diff = get_diff(i, spec);
	ch = get_fill_ch(spec);
	while (i + diff < spec->width.value)
	{
		ft_putchar(ch);
		i++;
	}
	return (i - len);
}

int fill_precision_field(char *buf, t_spec *spec)
{
	int diff;
	int i;
	int len;

	i = 0;
	len = ft_strlen(buf);
	diff = get_diff(len, spec);
	while (diff > 0)
	{
		ft_putchar('0');
		diff--;
		i++;
	}
	return (i);
}

size_t print_buf(const char *buf)
{
	if (buf)
		ft_putstr(buf);
	return (ft_strlen(buf));
}

int	print_digit_buf(char *digit, t_spec *spec, t_put_prefix pp)
{
	int 	i;
	char	dig_buf[MAX_HEX_BUF_SIZE];
	int		was_prefix;

	was_prefix = prepare_buf(digit, spec, dig_buf, pp);
	i = 0;
	if (spec->flags['-'] == TRUE)
	{
		i += fill_precision_field(dig_buf, spec);
		i += print_buf(dig_buf);
		i += fill_width_field(i, spec);
	}
	else
	{
		if (was_prefix && spec->flags['0'] == TRUE)
		{
			i += pp(digit, spec, NULL);
			i += fill_width_field(ft_strlen(digit) + i, spec);
			i += fill_precision_field(digit, spec);
			i += print_buf(digit);
		}
		else
		{
			i += fill_width_field(ft_strlen(dig_buf), spec);
			i += fill_precision_field(dig_buf, spec);
			i += print_buf(dig_buf);
		}
	}
	if (spec->flags[' '] && spec->type == 'd' && spec->flags['+'] == FALSE && digit[0] != '-')  //SUCH AN AWFUL FT_COSTYL
		i++;
	return (i);
}