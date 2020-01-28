/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:45:40 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 15:47:16 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_float.h"

int		ft_print_f(t_spec *spec, va_list *args)
{
    t_exp   e;
	char	*buffer;
	int		count;

	buffer = ft_memalloc(MAX_LD_BUF_SIZE + 10);
	get_f(args, spec, buffer);
	count = print_f(buffer, spec);
	free(buffer);
	return (count);
}

int		ft_print_e(t_spec *spec, va_list *args)
{
	char	*buffer;
	int		count;

	buffer = ft_memalloc(MAX_LD_BUF_SIZE + 10);
	get_f(args, spec, buffer);
	count = print_e_buf(buffer, spec, 'e');
	free(buffer);
	return (count);
}

int		ft_print_ee(t_spec *spec, va_list *args)
{
    t_exp   e;
	char	*buffer;
	int		count;

	buffer = ft_memalloc(MAX_LD_BUF_SIZE + 10);
	get_f(args, spec, buffer);
	count = print_e_buf(buffer, spec, 'E');
	free(buffer);
	return (count);
}
