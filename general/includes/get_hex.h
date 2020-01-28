/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:45:07 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 21:45:23 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_GET_HEX_H
# define PRINTF_GET_HEX_H

# include <stdarg.h>
# include "specificator.h"
# include "convert.h"
# include "get_digit.h"

void	get_hex(va_list *va_args, t_spec *spec, char *buffer, char letter);

#endif
