/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:40:33 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 17:41:23 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_basic.h"

int		ft_print_d(t_spec *spec, va_list *args)
{
	char buffer[MAX_LL_BUFF_SIZE];

	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	get_sd(args, spec, buffer);
	return (print_sd_buf(buffer, spec));
}

int		ft_print_p(t_spec *spec, va_list *args)
{
	char buffer[MAX_P_BUFF_SIZE];

	ft_bzero(buffer, MAX_P_BUFF_SIZE);
	get_p(args, spec, buffer);
	spec->flags['#'] = TRUE;
	return (print_d_buf(buffer, spec, put_hex_prefix));
}

int		ft_print_dd(t_spec *spec, va_list *args)
{
	char buffer[MAX_LL_BUFF_SIZE];

	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	spec->size.value[0] = 'l';
	get_ud(args, spec, buffer);
	return (print_sd_buf(buffer, spec));
}
