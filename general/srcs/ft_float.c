//
// Created by dan on 20.12.19.
//

#include "ft_float.h"
#include "libft.h"
#include "bits_util.h"
#include "printf_constants.h"
#include <stdlib.h>
#include <float.h>


#define EXP_SHIFT 16383

char *view_bin(unsigned long bin)
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

void init_float(t_float *f)
{
    f->ld = 0.0;
    f->exp = 0;
    f->is_up = 0;
    f->man = 0;
    f->sign = 0;
}

unsigned long   set_bit(unsigned long bin, unsigned n, unsigned long b)
{
    if (b > 0)
        bin |= (1U<< n);
    else if (b == 0)
        bin  &=  ~(1UL << n);
    return (bin);
}

unsigned long long get_mantissa_int_part(unsigned long m, unsigned e)
{
    unsigned long mask;
    unsigned long long decimal_part;

    decimal_part = 0;
    mask = 1u;
    mask <<= 63lu;
    e++;
    while (e)
    {
        decimal_part = set_bit(decimal_part, e - 1, m & mask);
        mask >>= 1u;
        e--;
    }
    return (decimal_part);
}

void get_int_part(unsigned long m, unsigned exp, char *buf)
{
    unsigned long long result;

    result = get_mantissa_int_part(m, exp);
    ft_ulltoa_base(result, buf, 10, 'a');
}

//void get_int_part(long double ld,  char *buf)
//{
//    unsigned long result;
//
//    result = (unsigned long)ld;
//    ft_ulltoa_base(result, buf, 10, 'a');
//}

//void get_int_part(unsigned long m, unsigned exp, char *buf)
//{
//    unsigned long mask;
//    int count;
//    unsigned long result;
//
//    mask = 1u;
//    count = 0;
//    while (!(m & mask))
//    {
//        mask <<= 1u;
//        count++;
//    }
//    m >>= count;
//    m >>= count_bits(m) - exp - 1;
//    result = bin_to_dec(m);
//    ft_ulltoa_base(result, buf, 10, 'a');
//}

//void    get_float_bits(unsigned long m, unsigned e, char *buf, int flag)
//{
//    unsigned long   mask;
//    int             count;
//    unsigned        i;
//    unsigned        max;
//    mask = 1u;
//    count = 0;
//    i = 0;
//    while (!(m & mask))
//    {
//        mask <<=1;
//        count++;
//    }
//    m >>= count;
//    mask = 1u; // what if count bits == 0 or e >2000 ?
//    max = flag == 1 ? count_bits(m) - e - 1: count_bits(m) + e - 1;
//    while (i < max)
//    {
//        if (m & mask)
//            buf[i++] = '1';
//        else
//            buf[i++] = '0';
//        m >>= 1;
//    }
//    buf[i] = '\0';
//    ft_strrev(buf);
//}


void    get_float_bits(unsigned long m, unsigned e, char *buf, int flag)
{
    unsigned long   mask;
    unsigned        i;

    mask = 1u;
    i = 0;
    if (flag)
        mask = mask << (63lu - (e + 1u));
    else
        mask <<= 63u;
    while (mask)
    {
        if (m & mask)
            buf[i++] = '1';
        else
            buf[i++] = '0';
        mask >>= 1;
    }
    buf[i] = '\0';
}

t_uchar*   print_mass(t_uchar *mass, int n)
{
    t_uchar *new;
    int     i;

    i = 0;
    new = ft_memalloc(n);
    while (i != n)
    {
        new[i] = mass[i] + '0';
        i++;
    }
    return (new);
}

t_uchar*   devide_by_two(t_uchar *devided, int n)
{
    int i;

    i = 0;
    while (i != n)
    {
        if (devided[i] % 2 == 1)
            devided[i + 1] += 10;
        devided[i] /= 2;
        i++;
    }
    return (devided);
}

void   set_res(t_uchar *result, int i, int swap, int *int_part)
{
    if (swap < 10)
        result[i] = swap;
    else
    {
        result[i] = swap - 10;
        if (i == 0)
            *int_part += 1;
        else
            set_res(result, i - 1, result[i - 1] + 1, int_part);
    }
}

int    summ_long(t_uchar *divided, t_uchar *result, int n)
{
    int i;
    int swap;
    int int_part;

    i = 0;
    int_part = 0;
    while(i != n)
    {
        swap = result[i] + divided[i];
        if (swap != 0 && divided[i] != 0)
            set_res(result, i, swap, &int_part);
        i++;
    }
    return int_part;
}

void    transform_float_part(const t_uchar *float_part, int n, char *buf)
{
    int i;

    i = 0;
    while (i < n)
    {
        buf[i] = (char)(float_part[i] + '0');
        i++;
    }
    buf[i] = '\0';
}

void add_float_zeros(char *buf, unsigned exp)
{
    char *zeros;
    zeros = ft_memalloc(MAX_FLOAT_BUFF_SIZE);
    while (exp != 1)
    {
        ft_strcat(zeros, "0");
        exp--;
    }
    ft_strcat(zeros, buf);
    ft_strcpy(buf, zeros);
    free(zeros);
}

void    get_float_part(unsigned long mantissa, unsigned exp, char *buf, int flag)
{
    char                        bin_buf[MAX_FLOAT_BUFF_SIZE];
    unsigned long long int      i;
    unsigned int                n;
    t_uchar                     *divided;
    t_uchar                     *result;

    i = 0;
    ft_bzero(bin_buf, MAX_FLOAT_BUFF_SIZE);
    get_float_bits(mantissa, exp, bin_buf, flag);
    if (flag == 0)
        add_float_zeros(bin_buf, exp);
    n = 0.3 * exp + 800; // Mansur's formula
    divided = ft_memalloc(n);
    result = ft_memalloc(n);
    ft_memset(divided, 0, n);
    ft_memset(result, 0, n );
    divided[0] = 5;
    while (bin_buf[i])
    {
        if (bin_buf[i] == '1')
            summ_long(divided, result, n);
        i++;
        divided = devide_by_two(divided, n);
    }
    transform_float_part(result, n, buf);
    free(divided);
    free(result);
}

//FT COSTYL
void    zero_case(char *buf)
{
    ft_strcpy(buf, "0.0");
}

#include <stdio.h>
#include <includes/ft_float.h>

void    ft_dtoa(long double ld, char *buffer)
{
    char int_part_buf[MAX_FLOAT_BUFF_SIZE];
    char float_part_buf[MAX_FLOAT_BUFF_SIZE];
    int flag;
    long_double_cast ldc;

    ft_bzero(int_part_buf, MAX_FLOAT_BUFF_SIZE);
    ft_bzero(float_part_buf, MAX_FLOAT_BUFF_SIZE);
    if (ld == 0 || ld == LDBL_MIN)
    {
        zero_case(buffer);
        return;
    }
    else if (ld == -LDBL_MIN)
    {
        ft_strcpy(buffer, "-0.0");
        return;
    }
    ldc = (long_double_cast) {.ld = ld};
    if (ldc.parts.exponent >= EXP_SHIFT)
    {

        ldc.parts.exponent = ldc.parts.exponent - EXP_SHIFT;
        //get_int_part(ld < 0 ? -ld : ld, int_part_buf);
        get_int_part(ldc.parts.mantissa, ldc.parts.exponent, int_part_buf);
        flag = 1;
    }
    else
    {
        ldc.parts.exponent = EXP_SHIFT - ldc.parts.exponent;
        ft_strcpy(int_part_buf, "0");
        flag = 0;
    }

    get_float_part(ldc.parts.mantissa, ldc.parts.exponent, float_part_buf, flag);
    if (ld < 0)
        buffer[0] = '-';
    ft_strcat(buffer, int_part_buf);
    ft_strcat(buffer, ".");
    ft_strcat(buffer, float_part_buf);
}

