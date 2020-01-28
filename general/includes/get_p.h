/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_p.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:46:19 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 21:46:38 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_GET_P_H
# define PRINTF_GET_P_H

# include <stdarg.h>
# include <specificator.h>

void		get_p(va_list *va_args, t_spec *spec, char *buffer);

#endif
