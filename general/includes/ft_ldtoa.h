/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_float.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:44:16 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 21:44:37 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FT_LDTOA_H
# define PRINTF_FT_LDTOA_H

# include <stdarg.h>

# include "specificator.h"
# include "ft_float.h"
# include "float_convert.h"

void	get_general_float(va_list *va_args, t_spec *spec, char *buffer);

#endif
