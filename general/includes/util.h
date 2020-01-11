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


typedef struct s_pair
{
	size_t x;
	size_t y;
}				t_pair;

t_pair		*ft_strfind(const char *str, const char *charset);

ssize_t		ft_arr_find(const char **str_arr, size_t size, const char *s);


typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

#endif //PRINTF_UTIL_H
