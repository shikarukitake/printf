/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit_buf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 20:03:01 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/22 20:14:26 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_digit_buf.h"

int		fill_prefix_width_field(int i, t_spec *spec, int prefix)
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

int		check_is_prefix(char *digit, t_spec *spec, t_put_prefix pp)
{
	char	dest[4];
	int		is_prefix;

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

int		prepare_prefixed_pbuf(char *digit, t_spec *spec, char *dig_buf, t_put_prefix p)
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

int		fill_prec_and_print(char *digit, char *pdigit, t_spec *spec)
{
	int i;

	i = 0;
	i += fill_precision_field((spec->type == 'o' ? pdigit : digit), spec);
	i += print_buf(digit);
	return (i);
}

int 	print_d_buf_left(t_d_pair *p, t_spec *spec, t_put_prefix pp, int is_prefix)
{
	int i;

	i = 0;
	if (is_prefix && spec->flags['0'] == TRUE)
	{
		if (get_fill_ch(ft_strlen(p->d), spec) == ' ')
		{
			i += fill_prefix_width_field((int) ft_strlen(p->d), spec, is_prefix);
			i += pp(p->d, spec, NULL);
		}
		else
		{
			i += pp(p->d, spec, NULL);
			i += fill_prefix_width_field((int)ft_strlen(p->d), spec, is_prefix);
		}
		i += fill_prec_and_print(p->d, p->pd, spec);
	}
	else
	{
		i += fill_prefix_width_field(ft_strlen(p->d), spec, is_prefix);
		if (is_prefix)
			i += pp(p->d, spec, NULL);
		i += fill_prec_and_print(p->d, p->pd, spec);
	}
	return (i);
}

int		print_d_buf(char *digit, t_spec *spec, t_put_prefix pp)
{
	int			i;
	int			is_prefix;
	char		prefixed_digit[MAX_HEX_BUF_SIZE];
	t_d_pair	pair;

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
		pair.d = digit;
		pair.pd = prefixed_digit;
		i += print_d_buf_left(&pair, spec, pp, is_prefix);
	}
	return (i);
}
