/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oct_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:38:33 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 17:39:01 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_oct_buf.h"

int		is_oct_prefix(t_spec *spec)
{
	return (spec->type == 'o' && spec->flags['#'] == TRUE);
}

int		put_oct_prefix(const char *buf, t_spec *spec, char *dest)
{
	if (spec->flags['#'] == TRUE && buf[0] != '0')
	{
		if (spec->type == 'o')
		{
			if (dest)
				ft_strcpy(dest, OCT_PREFIX);
			else
				ft_putstr(OCT_PREFIX);
		}
		return (1);
	}
	return (0);
}
