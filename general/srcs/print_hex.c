/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:45:11 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/22 18:47:33 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_hex.h"

int		ft_print_x(t_spec *spec, va_list *args)
{
	char	buffer[MAX_HEX_BUF_SIZE];

	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	get_hex(args, spec, buffer, 'a');
	return (print_d_buf(buffer, spec, put_hex_prefix));
}

int		ft_print_xx(t_spec *spec, va_list *args)
{
	char	buffer[MAX_HEX_BUF_SIZE];

	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	get_hex(args, spec, buffer, 'A');
	return (print_d_buf(buffer, spec, put_hex_prefix));
}
