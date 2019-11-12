//
// Created by Aletha Yellin on 06/11/2019.
//

#include "ft_stdio.h"
#include <stdarg.h>

void	ft_putstr_args(const char *fmt, va_list args)
{

	ft_putstr(va_arg(args, char *));
}

void	ft_putnum_args(const char *fmt, va_list args)
{
	ft_putnbr((va_arg(args, int)));
}

void	ft_putempty(const char *fmt, va_list args)
{
	((void)fmt);
	((void)args);
}

void	ft_putpercent(const char *fmt, va_list args)
{
	(void)fmt;
	(void)(args);
	ft_putchar('%');
}

void 	(*pn[4])(const char *, va_list) = {
		ft_putempty,
		ft_putstr_args,
		ft_putnum_args,
		ft_putpercent
};

typedef struct s_pair
{
	size_t x;
	size_t y;
}				t_pair;

t_pair		*ft_init_pair(size_t i, size_t j)
{
	t_pair *ptr;

	ptr = ft_memalloc(sizeof(t_pair));
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
static const char *g_specificators = "cpsdiouxX";

int 	find_flag(char flag)
{
	if (flag == 's')
		return (1);
	if (flag == 'd')
		return (2);
	if (flag == '%')
		return (3);
	else
		return (0);
}

int	get_id(const char *spec)
{
	t_pair *p;

	if((p = ft_strfind(spec, g_specificators)))
		return (find_flag(spec[p->x]));
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	size_t i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			pn[get_id(format + i + 1)](format + i + 1, args);
			i++; // i += some_x
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (0);
}