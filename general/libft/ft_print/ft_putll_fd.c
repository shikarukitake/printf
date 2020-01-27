/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putll_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:21:07 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/27 19:21:19 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	ft_putll_fd(long long l, const int fd)
{
	if (l < 0)
	{
		if (l == LONG_LONG_MIN)
		{
			ft_putstr_fd(ft_lltoa(l, NULL), fd);
			return ;
		}
		l = -l;
		ft_putchar_fd('-', fd);
	}
	if (l < 10)
	{
		ft_putchar_fd((char)(l + '0'), fd);
		return ;
	}
	ft_putll_fd(l / 10, fd);
	ft_putll_fd(l % 10, fd);
}
