/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:33:53 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 21:40:23 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FT_FLOAT_H
# define PRINTF_FT_FLOAT_H

typedef	union			u_ldc
{
	long double			ld;
	struct
	{
		unsigned long	m : 64;
		unsigned int	e : 15;
		unsigned int	s : 1;
	}					parts;
}						t_ldc;

void					ft_dtoa(long double ld, char *buffer);

#endif
