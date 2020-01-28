/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:41:32 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 17:41:52 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_oct.h"

int		ft_print_o(t_spec *spec, va_list *args)
{
	char	buffer[MAX_LL_BUFF_SIZE];

	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	get_oct(args, spec, buffer, 'a');
	return (print_d_buf(buffer, spec, put_oct_prefix));
}
