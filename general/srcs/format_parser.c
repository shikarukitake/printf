//
// Created by Aletha Yellin on 20/11/2019.
//

#include "ft_printf.h"

int		get_format_length(const char *format)
{
	return (ft_strcspn(format, g_specificators));
}