//
// Created by Aletha Yellin on 29/11/2019.
//

#include "ft_printf.h"

size_t print_sd(va_list vargs, t_spec *spec, char *buffer)
{
	int		i_v;
	size_t	size;

	size = 0;
	i_v = va_arg(vargs, int);
	ft_itostr(i_v, buffer);
	if(spec->flags['+'] && i_v > 0)
	{
		ft_putchar('+');
		size++;
	}
	ft_putstr(buffer);
	size += ft_strlen(buffer);
	return (size);
}

size_t print_sl(va_list vargs, t_spec *spec, char *buffer)
{
	long	l_v;
	size_t	size;

	size = 0;
	l_v = va_arg(vargs, long);
	ft_lltoa(l_v, buffer);
	if(spec->flags['+'] && l_v > 0)
	{
		ft_putchar('+');
		size++;
	}
	ft_putstr(buffer);
	size += ft_strlen(buffer);
	return (size);
}

size_t print_sll(va_list vargs, t_spec *spec, char *buffer)
{
	long	ll_v;
	size_t	size;

	size = 0;
	ll_v = va_arg(vargs, long long);
	ft_lltoa(ll_v, buffer);
	if(spec->flags['+'] && ll_v > 0)
	{
		ft_putchar('+');
		size++;
	}
	ft_putstr(buffer);
	size += ft_strlen(buffer);
	return (size);
}

size_t print_sh(va_list vargs, t_spec *spec, char *buffer)
{
	char	c_v;
	size_t	size;

	size = 0;
	c_v = (char)va_arg(vargs, int);
	ft_itostr(c_v, buffer);
	if(spec->flags['+'] && c_v > 0)
	{
		ft_putchar('+');
		size++;
	}
	ft_putstr(buffer);
	size += ft_strlen(buffer);
	return (size);
}

size_t print_shh(va_list vargs, t_spec *spec, char *buffer)
{
	short	s_v;
	size_t	size;

	size = 0;
	s_v = (short)va_arg(vargs, int);
	ft_itostr(s_v, buffer);
	if(spec->flags['+'] && s_v > 0)
	{
		ft_putchar('+');
		size++;
	}
	ft_putstr(buffer);
	size += ft_strlen(buffer);
	return (size);
}