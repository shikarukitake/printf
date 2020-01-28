/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_bch.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:14:08 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 22:14:18 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PUT_BCH_H
# define PRINTF_PUT_BCH_H

# include "libft.h"
# include <unistd.h>

int		put_bch(char ch);

size_t	put_bstr(char *s);

int		flush_buffer();

#endif
