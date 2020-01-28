/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_oct.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:45:43 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 21:46:00 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_GET_OCT_H
# define PRINTF_GET_OCT_H

# include <stdarg.h>

# include "convert.h"
# include "get_digit.h"
# include "specificator.h"

void		get_oct(va_list *vargs, t_spec *spec, char *buffer, char letter);

#endif
