/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_f_buf.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:00:36 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 18:00:42 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PREPARE_F_BUF_H
# define PRINTF_PREPARE_F_BUF_H

# include "libft.h"
# include "specificator.h"
# include "float_util.h"

void		add_sing_and_sp(char *f, t_spec *spec);

void		add_zeros(char *buf, t_spec *spec);

#endif
