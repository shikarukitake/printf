/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sd.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:47:16 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 21:47:24 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_GET_SD_H
# define PRINTF_GET_SD_H

# include <stdarg.h>
# include "specificator.h"
# include "convert.h"
# include "get_digit.h"

void		get_sd(va_list *va_args, t_spec *spec, char *buffer);

#endif
