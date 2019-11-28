//
// Created by Aletha Yellin on 28/11/2019.
//

#include "libft.h"
#include <limits.h>

void	ft_putll_fd(long long l, const int fd)
{
	if (l < 0)
	{
		if (l == LONG_LONG_MIN)
		{
			ft_putstr_fd(ft_lltoa(l, NULL, 10), fd);
			return ;
		}
		l = -l;
		ft_putchar_fd('-', fd);
	}
	if (l < 10)
	{
		ft_putchar_fd((char)(l + '0'), fd);
		return ;
	}
	ft_putll_fd(l / 10, fd);
	ft_putll_fd(l % 10, fd);
}