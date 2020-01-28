//
// Created by dan on 1/13/20.
//

#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef unsigned long long t_ull;

void reverse(char *str)
{
	size_t l;
	size_t i;
	char tmp;

	i = 0;
	l = strlen(str) - 1;
	while (i < l)
	{
		tmp = str[i];
		str[i] = str[l - i];
		str[l - i] = tmp;
		i++;
		l--;
	}
}


typedef struct s_ulldiv
{
	t_ull qout;
	t_ull rem;

}				t_ulldiv;

static t_ulldiv ull_div(t_ull value, int base)
{
	t_ulldiv r;

	r.qout = (value) / base;
	r.rem  = (value) % base;
	return (r);
}

static char	ft_convert(t_ull *ll, int base, char a)
{
	t_ulldiv r;
	char ch;

	r = ull_div(*ll, base);
	*ll = r.qout;
	ch = (char)(r.rem + ((9L < r.rem) ? (a - 10L) : '0'));
	return (ch);
}

static int	ft_is_border(t_ull value, char *str)
{
	if (value == 0)
	{
		strcpy(str, "0");
		return (1);
	}
	return (0);
}

char	*ft_ulltoa_base(long long ll, char *str, int base, char a)
{
	int		i;
	t_ull	ull;

	ull = 0;
	if (ll < 0)
		ull = ll;
	i = 0;
	if (36 < base || 2 > base)
		base = 10;
	while (ull)
		str[i++] = ft_convert(&ull, base, a);
	str[i] = '\0';
	reverse(str);
	return (str);
}

int main()
{
	char buffer[1024];

	bzero(buffer, 1024);
	ft_ulltoa_base(-0x2, buffer, 16, 'a');
	printf("answer is %s\n", buffer);
}

