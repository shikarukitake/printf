//
// Created by dan on 20.12.19.
//

#include "ft_float.h"
#include "libft.h"
#include "bits_util.h"
#include "printf_constants.h"

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
    result = bin_to_dec(m);
    ft_ulltoa_base(result, buf, 10, 'a');
}
char    *view_bin(unsigned long bin)
{
    char            *ptr;
    unsigned int    mask;
    int i;

    i = 0;
    mask =1u;
    ptr = ft_memalloc(1024);
    ft_bzero(ptr, 1024);
    while (bin)
    {
        if (bin & 1u)
          ptr[i++] = '1';
        else
            ptr[i++] = '0';
        bin >>= 1u;
    }
    ft_strrev(ptr);
    return (ptr);
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
        mask <<= 1u;
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
    char            bin_buf[MAX_FLOAT_BUFF_SIZE];
    int             i;
    unsigned int    n;
    long double     res;

    i = 0;
    n = 1;
    res = 0;
    ft_bzero(bin_buf, MAX_FLOAT_BUFF_SIZE);
    get_float_bits(mantissa, exp, bin_buf);
    while (bin_buf[i] && i < 30)
    {
        if (bin_buf[i] == '1')
            res = res + (1.0 / ft_power(2, n)); // need long arithmetic there
        n++;
        i++;
    }
    if(i > 6)
        i = 6;
    res = res * ft_power(10, i); // need long arithmetic there
    ft_ulltoa_base((t_ull)res, buf, 10, 'a');
}

char    a_plus_one(char a)
{
    return (char)(a - '0' + '1');
}

void    round_float(char *float_buf)
{
    size_t  i;
    int     add;

    i = ft_strlen(float_buf) - 1;
    add = 0;
    while (float_buf[i] > '5')
    {
    	if (float_buf[i] == '.')
			return;
    	if (float_buf[i] == '9')
        	float_buf[i] = '0';
    	else
		{
    		float_buf[i] = a_plus_one(float_buf[i]);
			return;
		}
        i--;
        add = 1;
    }
    if (add)
        float_buf[i] = a_plus_one(float_buf[i]);
}

#include "stdio.h" // FOR DEBUG

void    ft_dtoa(long double ld, char *buffer)
{
    char int_part_buf[MAX_FLOAT_BUFF_SIZE];
    char float_part_buf[MAX_FLOAT_BUFF_SIZE];
    int is_less_than_one;
    long_double_cast ldc;

    ldc = (long_double_cast) {.ld = ld};
    if (ldc.parts.exponent < EXP_SHIFT)
    {
        is_less_than_one = 1;
        ldc.parts.exponent = EXP_SHIFT - ldc.parts.exponent;
    }
    else
    {
        is_less_than_one = 0;
        ldc.parts.exponent -= EXP_SHIFT;
    }
    ft_bzero(int_part_buf, MAX_FLOAT_BUFF_SIZE);
    ft_bzero(float_part_buf, MAX_FLOAT_BUFF_SIZE);
    if (!is_less_than_one)
        get_int_part(ldc.parts.mantisa, ldc.parts.exponent, int_part_buf);
    else
        ft_strcpy(int_part_buf, "0");
    get_float_part(ldc.parts.mantisa, ldc.parts.exponent, float_part_buf);
    if (ld < 0)
        buffer[0] = '-';
    ft_strcat(buffer, int_part_buf);
    ft_strcat(buffer, ".");
    ft_strcat(buffer, float_part_buf);
    round_float(buffer);
}
