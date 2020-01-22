/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:42:08 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/22 17:45:38 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_float.h"
#include "special_float_values.h"



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

void	ft_dtoa(long double ld, char *buffer)
{
	char	*int_part_buf;
	char	*float_part_buf;
	int		less_than_one;
	t_ldc	ldc;

	ldc = (t_ldc) {.ld = ld};
	if (is_reserved_value(ldc, ld, buffer))
		return ;
	if (ldc.parts.e >= EXP_SHIFT)
	{
		ldc.parts.e = ldc.parts.e - EXP_SHIFT;
		int_part_buf = ft_memalloc(MAX_F_BUF_SIZE);
		get_long_int_part(ldc.parts.m, ldc.parts.e, int_part_buf);
		less_than_one = 1;
	}
	else
	{
		ldc.parts.e = EXP_SHIFT - ldc.parts.e;
		int_part_buf = ft_strdup("0");
		less_than_one = 0;
	}
	if (ldc.parts.e < 63u || less_than_one == 0)
	{
		float_part_buf = ft_memalloc(MAX_F_BUF_SIZE);
		get_float_part(ldc.parts.m, ldc.parts.e, float_part_buf, less_than_one);
	}
	else
		float_part_buf = ft_strdup("0");
	make_float_buffer(ld, buffer, int_part_buf, float_part_buf);
}
