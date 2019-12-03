//
// Created by Aletha Yellin on 20/11/2019.
//

#include "ft_printf.h"

t_pair		*ft_init_pair(size_t i, size_t j)
{
	t_pair *ptr;

	ptr = ft_memalloc(sizeof(t_pair));
	if (!ptr)
		return (NULL);
	ptr->x = i;
	ptr->y = j;
	return (ptr);
}

t_pair		*ft_strfind(const char *str, const char *charset)
{
	t_pair *p;

	p = ft_init_pair(0, 0);
	while (str[p->x])
	{
		if (str[p->x] == '%')
			return (p);
		p->y = 0;
		while (charset[p->y])
		{
			if (str[p->x] == charset[p->y])
				return (p);
			p->y++;
		}
		p->x++;
	}
	return (NULL);
}

ssize_t		ft_arr_find(const char **str_arr, size_t size, const char *s)
{
	ssize_t i;

	i = 0;
	if (!s)
		return (-1);
	while (i < size)
	{
		if (ft_strcmp(str_arr[i], s) == 0)
			return (i);
		i++;
	}
	return (-1);
}