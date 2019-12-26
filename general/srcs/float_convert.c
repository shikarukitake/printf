//
// Created by dan on 20.12.19.
//

#include "printf_constatns.h"
#include "libft.h"
#include "ft_float.h"
#include <stdarg.h>
#include "specificator.h"
#include "convert.h"



void reverse(char *str, int len)
{
	int i=0, j=len-1, temp;
	while (i<j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++; j--;
	}
}

int i_to_str(int x, char str[], int d)
{
	int i = 0;
	while (x)
	{
		str[i++] = (x%10) + '0';
		x = x/10;
	}
	while (i < d)
		str[i++] = '0';
	reverse(str, i);
	str[i] = '\0';
	return i;
}

void ft_ldtoa_base(long double val, char *buf, int base, char a)
{
	int				i;
	int				i_part;
	long double		f_part;
	int				afterpoint;

	afterpoint = 6;
	i_part = (int)val;
	f_part = val  - (long double)i_part;
	i = i_to_str(i_part, buf, 0);
	if (afterpoint != 0)
	{
		buf[i] = '.';
		f_part = f_part * ft_power(10, afterpoint);
		i_to_str((int)f_part, buf + i + 1, afterpoint);
	}
}


void ft_dtoa_base(double val, char *buf, int base, char a)
{
	int				i;
	int				i_part;
	long double		f_part;
	int				afterpoint;

	afterpoint = 6;
	i_part = (int)val;
	f_part = val  - (long double)i_part;
	i = i_to_str(i_part, buf, 0);
	if (afterpoint != 0)
	{
		buf[i] = '.';
		f_part = f_part * ft_power(10, afterpoint);
		i_to_str((int)f_part, buf + i + 1, afterpoint);
	}
}