/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_func_find.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:19:10 by ayellin           #+#    #+#             */
/*   Updated: 2019/11/22 16:19:23 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Returns the position of the character
 ** in the string for which the function returned 0
*/

ssize_t		ft_str_func_find(const char *s, int (*f)(char ch))
{
	ssize_t i;

	i = 0;
	while (s[i])
	{
		if (!f(s[i]))
			return (i);
		i++;
	}
	return (-1);
}
