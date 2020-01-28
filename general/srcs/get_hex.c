/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:50:57 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 17:51:12 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_hex.h"

void		get_hex(va_list *va_args, t_spec *spec, char *buffer, char letter)
{
	t_conv	conv;

	conv = (t_conv){0, 16, letter};
	get_general_ud(va_args, &conv, spec, buffer);
}
