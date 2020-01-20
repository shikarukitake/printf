//
// Created by dan on 20.12.19.
//

#include "ft_float.h"
#include "libft.h"
#include "bits_util.h"
#include "printf_constants.h"
#include <stdlib.h>
#include <float.h>

#include <stdio.h> //DEBUG

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


void    multiply_by_2(char *buf, int size, unsigned n)
{
    int carry;
    int i;
    unsigned p;

    carry = 0;
    i = 0;
    p = 0;
    while (p < n)
    {
        carry = 0;
        i = 0;
        while (i < size)
        {
            carry = carry + buf[i] * 2;
            buf[i] = carry % 10;
            carry /= 10;
            i++;
        }
        p++;
    }
}

void   set_float_res(char *result, int i, int swap, int *int_part)
{
    if (swap < 10)
        result[i] = swap;
    else
    {
        result[i] = swap - 10;
        set_float_res(result, i + 1, result[i + 1] + 1, int_part);
    }
}

int    sum_long_int(char *to_sum, char *result, int n)
{
    int i;
    int swap;
    int int_part;

    i = 0;
    int_part = 0;

    while(i != n)
    {
        swap = result[i] + to_sum[i];
        if (swap != 0 && to_sum[i] != 0)
            set_float_res(result, i, swap, &int_part);
        i++;
    }
    return int_part;
}

void    transform_long_result(char *buf, char *new_buf, int n)
{
    int i;
    int j;
    int last;

    last = n - 1;
    while (last > 0 && buf[last] == 0)
        last--;
    i = last;
    j = 0;
    while (i >= 0)
    {
        new_buf[j++] = (char)(buf[i] + '0');
        i--;
    }
    new_buf[j] = '\0';
}

static void	ch_swap(char *a, char *b)
{
    char tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}


void    float_reverse(char *buf, int n)
{
    size_t i;
    size_t j;

    i = 0;
    j = n - 1;
    while (i < j)
    {
        ch_swap(buf + i, buf + j);
        j--;
        i++;
    }
}

char*   divide_float_by_two(char *divided, int n)
{
    int i;

    i = 0;
    if (divided[0] == 1 && divided[1] == 0)
    {
        divided[0] = 0;
        return (NULL);
    }
    float_reverse(divided, n);
    while (i != n)
    {
        if (divided[i] == 0)
        {
            i++;
            continue;
        }
        if (divided[i] % 2 == 1)
            divided[i + 1] += 10;
        divided[i] /= 2;
        i++;
    }
    float_reverse(divided, n);
    return (divided);
}

void get_long_int_part(unsigned long m, unsigned e, char *buf)
{
    char    int_part[MAX_FLOAT_BUFF_SIZE];
    char    result[MAX_FLOAT_BUFF_SIZE];
    char    transformed_result[MAX_FLOAT_BUFF_SIZE];
    unsigned long mask;
    int was_mult;

    ft_bzero(transformed_result, MAX_FLOAT_BUFF_SIZE);
    ft_memset(result, 0, MAX_FLOAT_BUFF_SIZE);
    was_mult = 0;
    int_part[0] = 1;
    mask = 1u;
    int n = MAX_FLOAT_BUFF_SIZE;
    mask <<= 63lu;
    e++;
    while (e)
    {
        if ((mask & m) > 0)
        {
            if (!was_mult)
            {
                ft_memset(int_part, 0, MAX_FLOAT_BUFF_SIZE);
                int_part[0] = 1;
                multiply_by_2(int_part, n, e - 1);
                was_mult = 1;
            }
            sum_long_int(int_part, result, n);
        }
        if (was_mult)
            divide_float_by_two(int_part, n);
        mask >>= 1u;
        e--;
    }
    transform_long_result(result, buf, n);
}

//void get_long_int_part(unsigned long m, unsigned e, char *buf)
//{
//    char    int_part[MAX_FLOAT_BUFF_SIZE];
//    char    result[MAX_FLOAT_BUFF_SIZE];
//    char    transformed_result[MAX_FLOAT_BUFF_SIZE];
//    unsigned long mask;
//
//    ft_bzero(transformed_result, MAX_FLOAT_BUFF_SIZE);
//
//    ft_memset(result, 0, MAX_FLOAT_BUFF_SIZE);
//    int_part[0] = 1;
//    mask = 1u;
//    int n = MAX_FLOAT_BUFF_SIZE;
//    mask <<= 63lu;
//    e++;
//    while (e)
//    {
//        if ((mask & m) > 0)
//        {
//            ft_memset(int_part, 0, MAX_FLOAT_BUFF_SIZE);
//            int_part[0] = 1;
//            multiply_by_2(int_part, n, e - 1);
//            sum_long_int(int_part, result, n);
//        }
//        mask >>= 1u;
//        e--;
//    }
//    transform_long_result(result, buf, n);
//}

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
char*   devide_by_two(char *devided, int n)
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


void   set_res(char *result, int i, int swap, int *int_part)
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

int    summ_long(char *divided, char *result, int n)
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

void    transform_float_part(const char *float_part, int n, char *buf)
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
    char                     *divided;
    char                     *result;

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

void    ft_dtoa(long double ld, char *buffer)
{
    char *int_part_buf;
    char *float_part_buf;
    int flag;
    long_double_cast ldc;


    int_part_buf = ft_memalloc(MAX_FLOAT_BUFF_SIZE);
    float_part_buf = ft_memalloc(MAX_FLOAT_BUFF_SIZE);
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
        get_long_int_part(ldc.parts.mantissa, ldc.parts.exponent, int_part_buf);
       // get_int_part(ldc.parts.mantissa, ldc.parts.exponent, int_part_buf);
        flag = 1;
    }
    else
    {
        ldc.parts.exponent = EXP_SHIFT - ldc.parts.exponent;
        ft_strcpy(int_part_buf, "0");
        flag = 0;
    }
    if (ldc.parts.exponent < 63 || flag == 0)
        get_float_part(ldc.parts.mantissa, ldc.parts.exponent, float_part_buf, flag);
    if (ld < 0)
        buffer[0] = '-';
    ft_strcat(buffer, int_part_buf);
    ft_strcat(buffer, ".");
    ft_strcat(buffer, float_part_buf);
}

