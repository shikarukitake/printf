/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:48:40 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 17:50:05 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_ud.h"

void		get_ud(va_list *va_args, t_spec *spec, char *buffer)
{
	t_conv	conv;

	conv = (t_conv){0, 10, 'a'};
	get_general_ud(va_args, &conv, spec, buffer);
}
