/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_f.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:43:27 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 21:43:45 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_GET_F_H
# define PRINTF_GET_F_H

# include <stdarg.h>
# include "specificator.h"
# include "ft_ldtoa.h"
# include "get_float.h"

long double get_f(va_list *va_args, t_spec *spec, char *buffer);

#endif
