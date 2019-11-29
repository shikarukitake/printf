//
// Created by Aletha Yellin on 29/11/2019.
//

#include "ft_printf.h"

size_t get_hex(va_list vargs, t_spec *spec, char *buffer)
{
	int		i_v;
	size_t	size;

	size = 0;
	i_v = va_arg(vargs, int);
	ft_itoa_base(i_v, buffer, 16, 'a'); // TODO: function pointer in args and join this and other functions
	if (i_v < 0 && spec->flags['+'] == TRUE)
		spec->flags['+'] = FALSE;
	size += ft_strlen(buffer);
	return (size);
}

size_t get_hex_l(va_list vargs, t_spec *spec, char *buffer)
{
	long	l_v;
	size_t	size;

	size = 0;
	l_v = va_arg(vargs, long);
	ft_lltoa_base(l_v, buffer, 16, 'a');
	if (l_v < 0 && spec->flags['+'] == TRUE)
		spec->flags['+'] = FALSE;
	size += ft_strlen(buffer);
	return (size);
}

size_t get_hex_ll(va_list vargs, t_spec *spec, char *buffer)
{
	long	ll_v;
	size_t	size;

	size = 0;
	ll_v = va_arg(vargs, long long);
	ft_lltoa_base(ll_v, buffer, 16, 'a');
	if (ll_v < 0 && spec->flags['+'] == TRUE)
		spec->flags['+'] = FALSE;
	size += ft_strlen(buffer);
	return (size);
}

size_t get_hex_h(va_list vargs, t_spec *spec, char *buffer)
{
	char	c_v;
	size_t	size;

	size = 0;
	c_v = (char)va_arg(vargs, int);
	ft_itoa_base(c_v, buffer, 16, 'a');
	if (c_v < 0 && spec->flags['+'] == TRUE)
		spec->flags['+'] = FALSE;
	size += ft_strlen(buffer);
	return (size);
}

size_t get_hex_hh(va_list vargs, t_spec *spec, char *buffer)
{
	short	s_v;
	size_t	size;

	size = 0;
	s_v = (short)va_arg(vargs, int);
	ft_itoa_base(s_v, buffer, 16, 'a');
	if (s_v < 0 && spec->flags['+'] == TRUE)
		spec->flags['+'] = FALSE;
	size += ft_strlen(buffer);
	return (size);
}