//
// Created by dan on 1/15/20.
//

#include "print_digit_buf.h"

int is_null_case(const char *digit, t_spec *spec)
{
	int b;

	b = (digit[0] == '0' && spec->precision.is_dot == TRUE
	        && (spec->precision.value <= 0));
	if (spec->type == 'x' || spec->type == 'X' || spec->type == 'p')
		return (b);
	else
		return (b && spec->flags['#'] == FALSE);
}

int is_oct_prefix(t_spec *spec)
{
    return (spec->type == 'o' && spec->flags['#'] == TRUE);
}

int get_diff(int buf_len, t_spec *spec)
{
	if (spec->precision.value == -1 || spec->precision.value < buf_len)
		return (0);
	return (spec->precision.value - buf_len);
}


char get_fill_ch(int len, t_spec *spec)
{
    if (spec->flags['0'] == TRUE  && spec->precision.value < spec->width.value && spec->precision.value != -1)
        return ' ';
    if (spec->flags['0'] == TRUE  && spec->precision.value < len && spec->precision.value != -1)
        return ' ';
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
	diff = get_diff(i, spec) ;
	ch = get_fill_ch(i, spec);
	while (i + diff < spec->width.value)
	{
		ft_putchar(ch);
		i++;
	}
	return (i - len);
}

int fill_prefix_width_field(int i, t_spec *spec, int prefix)
{
    char	ch;
    int		len;
    int		diff;

    len = i;
    diff = get_diff(i, spec);
    ch = get_fill_ch(i + prefix, spec);
    if (is_oct_prefix(spec) && diff != 0)
        prefix = 0;
    while (i + diff + prefix < spec->width.value)
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


int check_is_prefix(char *digit, t_spec *spec, t_put_prefix pp)
{
    char dest[4];
    int is_prefix;

    ft_bzero(dest, 4);
    if (is_null_case(digit, spec))
    {
        ft_bzero(digit, MAX_HEX_BUF_SIZE);
        if (spec->type != 'p')
            return (0);
    }
    is_prefix = pp(digit, spec, dest);
    if (is_prefix)
        return (ft_strlen(dest));
    else
        return (0);
}

int prepare_prefixed_pbuf(char *digit, t_spec *spec, char *dig_buf, t_put_prefix p)
{
    int was_prefix;

    ft_bzero(dig_buf, MAX_HEX_BUF_SIZE);
    if (is_null_case(digit, spec))
    {
        ft_bzero(digit, MAX_HEX_BUF_SIZE);
        if (spec->type != 'p')
            return (0);
    }
    was_prefix = p(digit, spec, dig_buf);
    ft_strcat(dig_buf, digit);
    return (was_prefix);
}

int	print_d_buf(char *digit, t_spec *spec, t_put_prefix pp)
{
    int 	i;
    int		is_prefix;
    char    prefixed_digit[MAX_HEX_BUF_SIZE];

    i = 0;
    is_prefix = check_is_prefix(digit, spec, pp);
    prepare_prefixed_pbuf(digit, spec, prefixed_digit, pp);
    if (spec->flags['-'] == TRUE)
    {
        if (is_prefix)
            i += pp(digit, spec, NULL);
        i += fill_precision_field((spec->type == 'o' ? prefixed_digit : digit), spec);
        i += print_buf(digit);
        i += fill_width_field(i, spec);
    }
    else
    {
        if (is_prefix && spec->flags['0'] == TRUE)
        {
            if (get_fill_ch(ft_strlen(digit), spec) == ' ')
            {
                i += fill_prefix_width_field((int) ft_strlen(digit), spec, is_prefix);
                i += pp(digit, spec, NULL);
            }
            else
            {
                i += pp(digit, spec, NULL);
                i += fill_prefix_width_field((int) ft_strlen(digit), spec, is_prefix);
            }
            i += fill_precision_field((spec->type == 'o' ? prefixed_digit : digit), spec);
            i += print_buf(digit);
        }
        else
        {
            i += fill_prefix_width_field(ft_strlen(digit), spec, is_prefix);
            if (is_prefix)
                i += pp(digit, spec, NULL);
            i += fill_precision_field(spec->type == 'o' ? prefixed_digit : digit, spec);
            i += print_buf(digit);
        }
    }
    return (i);
}

char get_sign(char *digit, t_spec *spec)
{

    if (digit[0] == '-')
    {
        ft_strcpy(digit, digit + 1);
        return '-';
    }
    else if (spec->flags['+'] == TRUE)
    {
        return '+';
    }
    return ('\0');
}

int print_sign(char sign)
{
    if (sign)
    {
        ft_putchar(sign);
        return (1);
    }
    return (0);
}

int fill_sign_width_field(int i, t_spec *spec, char sign)
{
    char	ch;
    int		len;
    int		diff;

    len = i;
    diff = get_diff(i, spec);
    ch = get_fill_ch(i + IS_SIGN(sign), spec);
    while (i + diff + IS_SIGN(sign) < spec->width.value)
    {
        ft_putchar(ch);
        i++;
    }
    return (i - len);
}

int	print_sd_buf(char *digit, t_spec *spec)
{
	int 	i;
	char    sign;

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
	    if (get_fill_ch((int)ft_strlen(digit) + IS_SIGN(sign), spec) == ' ')
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
	if (is_need_wh(digit, spec) && !IS_SIGN(sign))  //SUCH AN AWFUL FT_COSTYL maybe error with negative values ???
		i++;
	return (i);
}