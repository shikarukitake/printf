/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit_buf.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:59:53 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 22:03:37 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PRINT_DIGIT_BUF_H
# define PRINTF_PRINT_DIGIT_BUF_H

# include "specificator.h"
# include "printf_constants.h"
# include "libft.h"
# include "print_d_buf.h"
# include "print_oct_buf.h"

typedef int(*t_put_prefix) (const char *, t_spec *, char *dest);

int			print_sign(char sign);

int			print_sd_buf(char *digit, t_spec *spec);

int			print_d_buf(char *digit, t_spec *spec, t_put_prefix pp);

char		get_sign(char *digit, t_spec *spec);

#endif
