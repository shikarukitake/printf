/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_e_buf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:42:05 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 17:42:14 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_e_buf.h"

int first_digit(char ch)
{
	return (ch > '0' && ch <= '9');
}

int get_exp(char *e)
{
	int dot;
	int digit;

	dot = ft_strchri(e, '.');
	digit = ft_str_find(e, first_digit);
	if (dot == -1 || digit == -1)
		return (0);
	if (digit < dot)
		return (dot - digit - 1);
	else
		return -(digit - dot);
}

int		display_exp(int exp)
{
	int		i;
	char	tmp[80];

	ft_bzero(tmp, 80);
	i = 1;
	if (exp < 0)
	{
		ft_putchar('-');
		exp = -exp;
	}
	else
		ft_putchar('+');
	if (exp < 10)
	{
		ft_putchar('0');
		i++;
	}
	ft_itoa_base(exp, tmp, 10, 'a');
	ft_putstr(tmp);
	i += ft_strlen(tmp);
	return (i);
}

/*
 *   [0] [1] [2] [3] [4] [5]
 *   [8] [8] [1] [.] [1] [5]
 *   [8] [8] [8] [.] [1] [5]
 *   [8] [8] [8] [8] [1] [5]
 *   [8] [.] [8] [1] [1] [5]
 *
 *   from = 3
 *   to   = 1
 */

int 	str_shift_left(char *buf, int from, int to)
{
	int		i;
	char	temp;

	i = from;
	while (i != to)
	{
		temp = buf[i - 1];
		buf[i - 1] = buf[i];
		buf[i] = temp;
		i--;
	}
	return (0);
}

int		float_shift_left_one(char *e)
{
	int		begin;
	int		i;

	begin = (e[0] == '-' ? 2 : 1);
	e[begin - 1] = e[begin + 1];
	i = begin + 1;
	while (e[i + 1])
	{
		e[i] = e[i + 1];
		i++;
	}
	return (0);
}

int 	float_shift_left_n(char *e, int exp)
{
	int	begin;
	int	i;

	exp = -exp;
	begin = (e[0] == '-' ? 2 : 1);
	e[begin - 1] = e[begin + (exp)];
	i = begin + (exp);
	while (e[i + 1])
	{
		e[i - exp + 1] = e[i + 1];
		e++;
	}
	return (0);
}

int		place_dot(char *e, int exp)
{
	int		begin;

	if (exp == 0)
		return (0);
	begin = (e[0] == '-' ? 2 : 1);
	if (exp > 0)
		str_shift_left(e, (int)ft_strchri(e, '.'), begin);
	else if (exp == -1)
		float_shift_left_one(e);
	else
		float_shift_left_n(e, exp);
	//e[begin + 1 + get_float_precision(spec)] = '\0';
	return (0);
}

int		print_e_buf(char *e, t_spec *spec, char a)
{
	int exp;

	exp = get_exp(e);
	place_dot(e, exp);
	print_f(e, spec);
	//ft_putstr(e);
	ft_putchar(a);
	display_exp(exp);
	return (0);
}

/*   0  1  2  3  4  5  6        0  1  2  3  4  5
 *  [8, 8, 1, ., 1, 5, 6 ]
 *  [8, ., 8, 1, 1, 5]
 */