/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:49:22 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/22 18:50:22 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_p(va_list *va_args, t_spec *spec, char *buffer)
{
	t_conv	conv;

	conv = (t_conv){0, 16, 'a'};
	get_general_ptr(va_args, &conv, spec, buffer);
}
