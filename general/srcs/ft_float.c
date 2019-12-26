//
// Created by dan on 20.12.19.
//

#include "ft_float.h"
#include "libft.h"
#include "bits_util.h"

#define FLOAT_MAX_BUF_SIZE 4096

#define EXP_SHIFT 16383

void init_float(t_float *f)
{
	f->ld = 0.0;
	f->exp = 0;
	f->is_up = 0;
	f->man = 0;
	f->sign = 0;
}

void get_int_part(unsigned long m, unsigned exp, char *buf)
{
    unsigned long mask;
    int count;
    unsigned long result;

    mask = 1u;
    count = 0;
    while (!(m & mask))
    {
        mask <<=1;
        count++;
    }
    m >>= count;
    m >>= count_bits(m) - exp - 1;
    view_bin(m);
    result = bin_to_dec(m);
    ft_ulltoa_base(result, buf, 10, 'a');
}

void    get_float_bits(unsigned long m, unsigned e, char *buf)
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
    max = count_bits(m) - e - 1;
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

void    get_float_part(unsigned long mantissa, unsigned exp, char *buf)
{
    char            bin_buf[FLOAT_MAX_BUF_SIZE];
    int             i;
    unsigned int    n;
    float           res;

    i = 0;
    n = 1;
    res = 0;
    ft_bzero(bin_buf, FLOAT_MAX_BUF_SIZE);
    get_float_bits(mantissa, exp, bin_buf);
    while (bin_buf[i])
    {
        if (bin_buf[i] == '1')
            res = res + (1.0 / ft_power(2, n));
        n++;
        i++;
    }
    res = res * ft_power(10, i);
    ft_itoa_base((int)res, buf, 10, 'a');
}

void    ft_dtoa(long double ld, char *buffer)
{
    char int_part_buf[FLOAT_MAX_BUF_SIZE];
    char float_part_buf[FLOAT_MAX_BUF_SIZE];
    long_double_cast ldc;

    ldc = (long_double_cast) {.ld = ld};
    ldc.parts.exponent -= EXP_SHIFT;
    ft_bzero(int_part_buf, FLOAT_MAX_BUF_SIZE);
    ft_bzero(float_part_buf, FLOAT_MAX_BUF_SIZE);
    get_int_part(ldc.parts.mantisa, ldc.parts.exponent, int_part_buf);
    get_float_part(ldc.parts.mantisa, ldc.parts.exponent, float_part_buf);
    ft_strcpy(buffer, int_part_buf);
    ft_strcat(buffer, ".");
    ft_strcat(buffer, float_part_buf);
}