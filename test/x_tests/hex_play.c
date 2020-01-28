//
// Created by dan on 1/11/20.
//

#include <stdio.h>
#include <string.h>

char	*ft_itoa_base(int value, char *buffer, int base, char a)
{
	long	n;
	int		sign;
	int		i;

	n = (value < 0) ? -(long)value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	buffer[i] = '\0';
	n = (value < 0) ? -(long)value : value;
	while (i-- + sign)
	{
		buffer[i] = (n % base < 10) ? n % base + '0' : n % base + a - 10;
		n /= base;
	}
	(i == 0) ? buffer[i] = '-' : 0;
	return (buffer);
}

void	print_bits(unsigned x);

char *neg_hex(int hex, char *buffer)
{
	unsigned int x;

	if (hex < 0)
	{
		hex = -hex;
		x = ~((unsigned)hex);
		x = x + 1;
		return (ft_itoa_base(x, buffer, 16, 'a'));
	}
}

#define MAX_UINT 2147483648u

void	print_bits(unsigned x)
{
	int i;

	i = 31;
	while (i >= 0)
	{
		if ((x >> i) & 1u)
			printf("1");
		else
			printf("0");
		i--;
	}

}

#include <stdlib.h>


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

void fill_hex_letters(char *buf, char a)
{
	char digit;
	int i;
	char c;

	digit = '0';
	i = 0;
	c = (a == 'a' ? 'a' : 'A');
	while (i <= 15){
		if (i < 10) {
			buf[i++] = digit++;
		}
		else {
			buf[i++] = c++;
		}
	}
}

void int_to_hex(int num, char *buffer, char a)
{
	char hex_letters[16];
	int i;

	i = 0;
	fill_hex_letters(hex_letters, a);
	if (!num) {
		buffer[0] = '0';
		return;
	}
	if (num > 0) {
		while (num) {
			buffer[i++] = hex_letters[num % 16];
			num /= 16;
		}
	}
	else {
		unsigned n = num;
		while (n) {
			buffer[i++] = hex_letters[n % 16];
			n /= 16;
		}
	}
	buffer[i] = '\0';
	reverse(buffer);
}

void llong_to_hex(unsigned long num, char *buffer, char a)
{
	char hex_letters[16];
	int i;

	i = 0;
	fill_hex_letters(hex_letters, a);
	if (!num) {
		buffer[0] = '0';
		return;
	}
	if (num > 0) {
		while (num) {
			buffer[i++] = hex_letters[num % 16];
			num /= 16;
		}
	}
	else {
		unsigned long n = num;
		while (n) {
			buffer[i++] = hex_letters[n % 16];
			n /= 16;
		}
	}
	buffer[i] = '\0';
	reverse(buffer);
}

int main()
{
	long long		h = -0x26;
	char	buffer[1024];

	bzero(buffer, 1024);
	printf("correct answer = %llx\n", h);

	printf("yours =  %s\n", ft_itoa_base(h, buffer, 16, 'a'));

	bzero(buffer, 1024);
	printf("correct yours = %s\n", neg_hex(h, buffer));
	print_bits(-2);
	putchar('\n');

	bzero(buffer, 1024);
	llong_to_hex(h, buffer, 'a');
	printf("from internet = %s\n", buffer);


}