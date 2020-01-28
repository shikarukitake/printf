/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oct_buf.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:10:16 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 22:10:29 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PRINT_OCT_BUF_H
# define PRINTF_PRINT_OCT_BUF_H

# include "specificator.h"
# include "printf_constants.h"
# include "print_f_buf.h"

int		put_oct_prefix(const char *buf, t_spec *spec, char *dest);

int		is_oct_prefix(t_spec *spec);

#endif
