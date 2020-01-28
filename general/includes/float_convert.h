/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_convert.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:33:36 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 21:33:41 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FLOAT_CONVERT_H
# define PRINTF_FLOAT_CONVERT_H

void ft_ldtoa_base(long double val, char *buf, int base, char a);

void ft_dtoa_base(double d, char *buf, int base, char a);

#endif
