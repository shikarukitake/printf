/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:16:34 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/28 19:16:36 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_util.h"

int		first_digit(char ch)
{
	return (ch > '0' && ch <= '9');
}

int		get_exp(char *e)
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
		return (-(digit - dot));
}

void	add_exp(int exp, char * e)
{
	char	tmp[80];

	ft_bzero(tmp, 80);
	if (exp < 0)
	{
		ft_strcat(e, "-");
		exp = -exp;
	}
	else
		ft_strcat(e, "+");
	if (exp < 10)
		ft_strcat(e, "0");
	ft_itoa_base(exp, tmp, 10, 'a');
	ft_strcat(e, tmp);
}