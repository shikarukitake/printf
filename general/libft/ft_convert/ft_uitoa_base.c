//
// Created by Aletha Yellin on 03/12/2019.
// TODO: CHECK THIS! MAYBE WRONG

char	*ft_uitoa_base(unsigned int value, char *buffer, int base, char a)
{
	unsigned long	n;
	int				i;

	n = value;
	i = 2; //TODO: ATTENTNTION!
	while ((n /= base) >= 1)
		i++;
	buffer[i] = '\0';
	n = value;
	while (i--)
	{
		buffer[i] = (n % base < 10) ? n % base + '0' : n % base + a - 10;
		n /= base;
	}
	return (buffer);
}