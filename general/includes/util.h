//
// Created by Aletha Yellin on 20/11/2019.
//

#ifndef PRINTF_UTIL_H
#define PRINTF_UTIL_H

# include <string.h>
# ifdef __linux__
#  include <sys/types.h>
# endif

#include "libft.h"

ssize_t		ft_arr_find(const char **str_arr, size_t size, const char *s);

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

#endif //PRINTF_UTIL_H
