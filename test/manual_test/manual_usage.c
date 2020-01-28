//
// Created by dan on 1/11/20.
//

#include "ft_printf.h"
#include <float.h>
#include <string.h>

void		change_first_digits(char *buf)
{
	char tmp[MAX_LD_BUF_SIZE];

	ft_strcpy(tmp, buf);
	if (tmp[0] != '-')
	{
		ft_strcpy(buf, "10");
		ft_strcat(buf, tmp + 1);
	}
	else
	{
		ft_strcpy(buf, "-10");
		ft_strcat(buf, tmp + 2);
	}
}

void		round_int_part(char *buf)
{
	int i;
	int is_sign;

	i = ft_strchri(buf, '.');
	is_sign = (buf[0] == '-');
	i--;
	while (i >= is_sign)
	{
		if (buf[i] == '9')
			buf[i] = '0';
		else
		{
			buf[i] += 1;
			break;
		}
		i--;
	}
	if (i == -1 + is_sign && buf[is_sign] == '0')
		change_first_digits(buf);
}

int main()
{
	char tmp[] = "899.9999999";
	round_int_part(tmp);
	printf("%s", tmp);
}
