//
// Created by Aletha Yellin on 28/11/2019.
//

#include "libft.h"

char *ft_lltoa(long long ll, char *str)
{
	return ft_lltoa_base(ll, str, 10, 'a');
}