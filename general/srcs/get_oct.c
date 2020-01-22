/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_oct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:38:28 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/22 18:40:08 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_oct.h"

void	get_oct(va_list *vargs, t_spec *spec, char *buf, char a)
{
	t_conv	conv;

    conv = (t_conv){0, 8, a};
	get_general_ud(vargs, &conv, spec, buf);
}
