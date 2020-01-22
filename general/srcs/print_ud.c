/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:33:42 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/22 19:34:10 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_ud.h"

int		ft_print_u(t_spec *spec, va_list *args)
{
	char	buffer[MAX_LL_BUFF_SIZE];

	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	get_ud(args, spec, buffer);
	return (print_d_buf(buffer, spec, put_sign_prefix));
}
