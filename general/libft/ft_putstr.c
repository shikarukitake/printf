/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <ayellin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:14:20 by ayellin           #+#    #+#             */
/*   Updated: 2019/09/17 16:14:20 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

void	ft_putstr(char const *s)
{
//	if (s)
//		while (*s)
//			ft_putchar(*s++);

    size_t l;

    l = ft_strlen(s);
    write(1, s, l);
}
