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
	char	*buffer;
	int		count;
	t_ld	ld;

	buffer = ft_memalloc(MAX_LD_BUF_SIZE + 10);
	ld = get_general_float(args, spec, buffer);
	count = print_f(buffer, spec, &ld);
	free(buffer);
	return (count);
}

int		ft_print_e(t_spec *spec, va_list *args)
{
	char	*buffer;
	int		count;
	t_ld	ld;

	buffer = ft_memalloc(MAX_LD_BUF_SIZE + 10);
	ld = get_general_float(args, spec, buffer);
	ld.round = '5';
	count = print_e_buf(buffer, spec, spec->type, &ld);
	free(buffer);
	return (count);
}

int		ft_print_g(t_spec *spec, va_list *args)
{
	char	*buffer;
	int		count;
	t_ld	ld;

	buffer = ft_memalloc(MAX_LD_BUF_SIZE + 10);
	ld = get_general_float(args, spec, buffer);
	ld.round = '5';
	if (ld.is_float_part)
		count = print_e_buf(buffer, spec, spec->type == 'g' ? 'e' : 'E', &ld);
	else
	{
		spec->precision.value = 0;
		count = print_f(buffer, spec, &ld);
	}
	free(buffer);
	return (count);
}
