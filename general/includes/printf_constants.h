/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_constants.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:18:20 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 22:29:01 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PRINTF_CONSTANTS_H
# define PRINTF_PRINTF_CONSTANTS_H

# define MAX_SIZE_SPECS 8

# define MAX_LL_BUFF_SIZE 80

# define MAX_P_BUFF_SIZE 80

# define MAX_HEX_BUF_SIZE 80

# define MAX_F_BUF_SIZE 5000

# define FT_PRINTF_SPEC_TYPES "ncpsdiouxXaAeEfFgGD"

# define FT_PRINTF_TYPES "ncpsdiouxXaAeEfFgG%"

# define MAX_CHAR_BUF_SIZE 5

# define FT_CHAR_NULL "^@"

# define FT_PRINTF_FLAGS "-+ #0"

# define FT_PRINTF_INT_TYPES "diouxX"

# define HEX_SMALL_PREFIX  "0x"

# define HEX_BIG_PREFIX "0X"

# define BIN_PREFIX	"0b"

# define OCT_PREFIX "0"

typedef unsigned long long	t_ull;

typedef unsigned long		t_ul;

typedef unsigned char		t_uc;

typedef unsigned int		t_ui;

typedef unsigned short		t_us;

const char					*g_size_specs[MAX_SIZE_SPECS];

#endif
