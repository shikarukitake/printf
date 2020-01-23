/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:30:11 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 16:40:37 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "round_float.h"

void		change_first_digits(char *buf)
{
	char tmp[MAX_LD_BUF_SIZE];

	ft_strcpy(tmp, buf);
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

void		round_int_part(char *buf)
{
	int i;

	i = ft_strchri(buf, '.');
	if (buf[i - 1] < '9')
		buf[i - 1] += 1;
	else
	{
		buf[i - 1] = '0';
		i--;
		while (i > 0 && buf[i] == '9')
		{
			buf[i] = '0';
			i--;
		}
		if (i == 0 && buf[i + 1] == '0')
			change_first_digits(buf);
	}
}

int			round_float_part(char *buf, int i, int last)
{
	if (buf[i] > '4' && buf[i - 1] != '.')
	{
		i--;
		if (buf[i] != '9')
			buf[i] += 1;
		else if (buf[i] == '9')
		{
			buf[i--] = '0';
			while (buf[i] == '9')
				buf[i--] = '0';
			if (buf[i] != '.')
				buf[i] += 1;
			else
				round_int_part(buf);
		}
		buf[last] = '\0';
		return (1);
	}
	return (0);
}

void		round_float(char *buf, int precision)
{
	int i;
	int last;

	i = (int)ft_strchri(buf, '.') + precision + 1;
	buf[i + 1] = '\0';
	last = i;
	if (round_float_part(buf, i, last))
		return ;
	if (buf[i] > '4' && buf[i - 1] == '.')
		round_int_part(buf);
	buf[last] = '\0';
}
