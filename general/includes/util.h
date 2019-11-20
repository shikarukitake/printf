//
// Created by Aletha Yellin on 20/11/2019.
//

#ifndef PRINTF_UTIL_H
#define PRINTF_UTIL_H

typedef struct s_pair
{
	size_t x;
	size_t y;
}				t_pair;

t_pair		*ft_strfind(const char *str, const char *charset);

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

#endif //PRINTF_UTIL_H
