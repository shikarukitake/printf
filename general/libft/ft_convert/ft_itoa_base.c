//
// Created by Aletha Yellin on 29/11/2019.
//


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