//
// Created by Aletha Yellin on 25/11/2019.
//

#include "libft.h"
#include <stdlib.h>

#define FT_ERROR_EXIT 1

#define FT_STDERR 2

void		ft_exit(void *mem, const char *msg)
{
	if (!msg)
		ft_putstr_fd(msg, FT_STDERR);
	if (!mem)
		free(mem);
	exit(FT_ERROR_EXIT);
}