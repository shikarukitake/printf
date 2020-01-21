/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f_buf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:04:55 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 22:05:42 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PRINT_F_BUF_H
# define PRINTF_PRINT_F_BUF_H

# include "specificator.h"
# include "ft_float.h"
# include "libft.h"
# include "printf_constants.h"
# include "specificator.h"
# include "put_bch.h"
# include "print_digit_buf.h"
# include "print_str.h"

void	round_float(char *buf, int precision);

int		print_f_buf(char *f, t_spec *spec);

#endif
