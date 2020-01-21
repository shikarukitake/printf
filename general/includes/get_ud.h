/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ud.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:47:48 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 21:48:08 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_GET_UD_H
# define PRINTF_GET_UD_H

# include <stdarg.h>
# include "specificator.h"
# include "convert.h"
# include "get_digit.h"

void		get_ud(va_list *va_args, t_spec *spec, char *buffer);

#endif
