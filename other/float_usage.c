//
// Created by Aletha Yellin on 26/12/2019.
//

#include <stdio.h>
#include <limits.h>
#include "ft_float.h"
#include <string.h>
#include "libft.h"
char		*ft_strrev(char *str)
{
    size_t i;
    size_t j;
    char tmp;

    i = 0;
    j = strlen(str);
    if (j != 0)
        j--;
    while (i < j)
    {
        tmp = str[i];
        str[i]= str[j];
        str[j] = tmp;
        j--;
        i++;
    }
    return (str);
}


void print_long_double(long double d)
{
    long_double_cast cast = {.ld = d};

    printf("e = %u\n", cast.parts.exponent);
    printf("m = %lu\n", cast.parts.mantisa);
    printf("sign = %u\n", cast.parts.sign);
}

void get_bits(unsigned long n, char *buffer)
{
    int i;
    unsigned long mask;

    i = 0;
    mask = 1u;
    while (n)
    {
        if (n & mask)
            buffer[i++] = '1';
        else
            buffer[i++] = '0';
        n >>= 1;
    }
    buffer[i] = '\0';
    ft_strrev(buffer);
}


unsigned int    get_bits_count(unsigned long n)
{
    unsigned int i;

    i = 0;
    while (n)
    {
        i++;
        n >>= 1;
    }
    return (i);
}

unsigned long    get_int_part(unsigned long m, unsigned int exp)
{
    unsigned long mask;
    int count;

    mask = 1u;
    count = 0;
    while (!(m & mask))
    {
        mask <<=1;
        count++;
    }
    m >>= count;
    m >>= get_bits_count(m) - exp - 1;
    return (m);

}

unsigned long bin_to_dec(unsigned long b)
{
    unsigned long   dec_value;
    int             base;
    unsigned long   temp;
    unsigned long   last_digit;

    dec_value = 0;
    base = 1;
    temp = b;
    while (temp) {
        last_digit = temp % 2;
        temp = temp / 2;
        dec_value += last_digit * base;
        base = base * 2;
    }
    return (dec_value);
}


unsigned long get_float_part(unsigned long m, unsigned e, char *buf)
{
    unsigned long   mask;
    int             count;
    unsigned        i;
    unsigned        max;

    mask = 1u;
    count = 0;
    i = 0;
    while (!(m & mask))
    {
        mask <<=1;
        count++;
    }
    m >>= count;
    mask = 1u;
    max = get_bits_count(m) - e - 1;
    while (i < max)
    {
        if (m & mask)
            buf[i++] = '1';
        else
            buf[i++] = '0';
        m >>= 1;
    }
    buf[i] = '\0';
    ft_strrev(buf);
    return (0);
}

//char	*ft_itoa_base(int value, char *buffer, int base, char a)
//{
//    long	n;
//    int		sign;
//    int		i;
//
//    n = (value < 0) ? -(long)value : value;
//    sign = (value < 0 && base == 10) ? -1 : 0;
//    i = (sign == -1) ? 2 : 1;
//    while ((n /= base) >= 1)
//        i++;
//    buffer[i] = '\0';
//    n = (value < 0) ? -(long)value : value;
//    while (i-- + sign)
//    {
//        buffer[i] = (n % base < 10) ? n % base + '0' : n % base + a - 10;
//        n /= base;
//    }
//    (i == 0) ? buffer[i] = '-' : 0;
//    return (buffer);
//}

void count_float_part(const char *float_part, char *result)
{
    int             i;
    unsigned int    n;
    float           res;

    i = 0;
    n = 1;
    res = 0;
    while (float_part[i])
    {
        if (float_part[i] == '1')
            res = res + (1.0 / ft_power(2, n));
        n++;
        i++;
    }
    res = res * ft_power(10, i);
    ft_itoa_base((int)res, result, 10, 'a');
//    printf("Float result = %f\n", res);
}

#define TEST_BUF_SIZE 4096

void get_char_value(long double ld, char *buffer)
{
    long_double_cast cast = {.ld = ld};
    unsigned int exp;
    unsigned long integer_part;
    unsigned long  float_part;
    char *fractional_part[TEST_BUF_SIZE];
    bzero(fractional_part, TEST_BUF_SIZE);

    exp = cast.parts.exponent - 16383;

    char buf2[TEST_BUF_SIZE];
    bzero(buf2, TEST_BUF_SIZE);

    get_bits(cast.parts.mantisa, buf2);
    printf("m = %s\n", buf2);
    integer_part = get_int_part(cast.parts.mantisa, exp);

    char buf3[TEST_BUF_SIZE];
    bzero(buf2, TEST_BUF_SIZE);
    float_part = get_float_part(cast.parts.mantisa, exp, buf3);
    printf("Float_part = %s\n", buf3);

    char buf4[TEST_BUF_SIZE];
    bzero(buf4, TEST_BUF_SIZE);
    count_float_part(buf3, buf4);
    printf("counted float part = %s\n", buf4);

    get_bits(float_part, buffer);
    printf("decimal part = %ld\n", bin_to_dec(integer_part));
}

int main()
{

    double a;
    a = 881.15625;
    print_long_double(a);
    printf("ld[e] = %e\nld[f] = %f\nld[g] = %g\n", a, a, a);
    char buffer[TEST_BUF_SIZE];
    bzero(buffer, TEST_BUF_SIZE);
    get_char_value(a, buffer);
    printf("double value = %s\n", buffer);
    return (0);
}