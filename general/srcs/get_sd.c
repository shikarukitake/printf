/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:46:06 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 17:50:15 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_sd.h"

void		get_sd(va_list *va_args, t_spec *spec, char *buffer)
{
	t_conv	conv;

	conv = (t_conv){0, 10, 'a'};
	get_general_d(va_args, &conv, spec, buffer);
}
