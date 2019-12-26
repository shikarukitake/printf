//
// Created by Aletha Yellin on 26/12/2019.
//

#include <stdio.h>
#include <limits.h>
#include <includes/ft_float.h>
#include "ft_float.h"
#include <string.h>

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

    printf("exponent = %u\n", cast.parts.exponent);
    printf("mantissa = %lu\n", cast.parts.mantisa);
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

int	ft_power(int base, unsigned int pow)
{
    if (pow == 0)
        return (1);
    else
        return (ft_power(base, pow - 1) * base);
}

unsigned long set_mask(unsigned int count)
{
    unsigned long mask;

    mask = ft_power(count, 2);
//    while (count)
//    {
//        mask <<=1;
//        mask = mask & 1u;
//        count--;
//    }
    return (mask);
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

unsigned long copy_n_bits(unsigned long x, unsigned n)
{
    unsigned  long result;

    result = 0;
    while (n)
    {
        result = result | (x & 1u);
        x >>= 1;
        result <<= 1;
        n--;
    }
    return (result);
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
}

void count_float_part(const char *float_part, char *result)
{
    unsigned int base;

    base = 1;

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
    printf("mantissa = %s\n", buf2);
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