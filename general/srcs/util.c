//
// Created by Aletha Yellin on 20/11/2019.
//

#include "util.h"

int		ft_arr_find(const char **str_arr, size_t size, const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (-1);
	while ((size_t )i < size)
	{
		if (ft_strcmp(str_arr[i], s) == 0)
			return (i);
		i++;
	}
	return (-1);
}