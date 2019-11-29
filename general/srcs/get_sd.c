//
// Created by Aletha Yellin on 29/11/2019.
//

#include "ft_printf.h"

size_t get_sd(va_list vargs, t_spec *spec, char *buffer)
{
	int		i_v;
	size_t	size;

	size = 0;
	i_v = va_arg(vargs, int);
	ft_itostr(i_v, buffer);
	if (i_v < 0 && spec->flags['+'] == TRUE)
		spec->flags['+'] = FALSE;
	size += ft_strlen(buffer);
	return (size);
}

size_t get_sl(va_list vargs, t_spec *spec, char *buffer)
{
	long	l_v;
	size_t	size;

	size = 0;
	l_v = va_arg(vargs, long);
	ft_lltoa(l_v, buffer);
	if (l_v < 0 && spec->flags['+'] == TRUE)
		spec->flags['+'] = FALSE;
	size += ft_strlen(buffer);
	return (size);
}

size_t get_sll(va_list vargs, t_spec *spec, char *buffer)
{
	long	ll_v;
	size_t	size;

	size = 0;
	ll_v = va_arg(vargs, long long);
	ft_lltoa(ll_v, buffer);
	if (ll_v < 0 && spec->flags['+'] == TRUE)
		spec->flags['+'] = FALSE;
	size += ft_strlen(buffer);
	return (size);
}

size_t get_sh(va_list vargs, t_spec *spec, char *buffer)
{
	char	c_v;
	size_t	size;

	size = 0;
	c_v = (char)va_arg(vargs, int);
	ft_itostr(c_v, buffer);
	if (c_v < 0 && spec->flags['+'] == TRUE)
		spec->flags['+'] = FALSE;
	size += ft_strlen(buffer);
	return (size);
}

size_t get_shh(va_list vargs, t_spec *spec, char *buffer)
{
	short	s_v;
	size_t	size;

	size = 0;
	s_v = (short)va_arg(vargs, int);
	ft_itostr(s_v, buffer);
	if (s_v < 0 && spec->flags['+'] == TRUE)
		spec->flags['+'] = FALSE;
	size += ft_strlen(buffer);
	return (size);
}