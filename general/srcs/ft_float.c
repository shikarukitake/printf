//
// Created by dan on 20.12.19.
//

#include "ft_float.h"
#include "libft.h"
#include "printf_constants.h"
#include <stdlib.h>
#include <float.h>

#define EXP_SHIFT 16383u

void    multiply_by_2(char *buf, int size, unsigned n)
{
    int carry;
    int i;
    unsigned p;

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

char*   divide_float_by_two(char *divided, int n)
{
    int i;

    i = n - 1;
    if (divided[0] == 1 && divided[1] == 0)
        return (NULL);
    while (i >= 0)
    {
        if (divided[i] == 0)
        {
            i--;
            continue;
        }
        if (divided[i] % 2 == 1 && i != 0)
            divided[i - 1] += 10;
        divided[i] /= 2;
        i--;
    }
    return (divided);
}


void get_long_int_part(unsigned long m, unsigned e, char *buf)
{
    char            int_part[MAX_FLOAT_BUFF_SIZE];
    char            result[MAX_FLOAT_BUFF_SIZE];
    unsigned long   mask;
    int             was_mult;
    int             n;

    n = MAX_FLOAT_BUFF_SIZE;
    ft_memset(result, 0, MAX_FLOAT_BUFF_SIZE);
    was_mult = 0;
    int_part[0] = 1;
    mask = 1u;

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

int is_inf(t_ldc ldc)
{
    return (ldc.parts.e == 32767u &&
			ldc.parts.m == 9223372036854775808ul &&
			ldc.parts.s == 0u);
}

int is_ninf(t_ldc ldc)
{
    return (ldc.parts.e == 32767u &&
			ldc.parts.m == 9223372036854775808ul &&
			ldc.parts.s == 1u);
}

int is_nan(t_ldc ldc)
{
    return (ldc.parts.e == 32767u &&
			(ldc.parts.m == 13835058057429647360ul || ldc.parts.m == 8u));
}

int is_reserved_value(t_ldc ldc, long double ld, char *fbuf)
{
    if (ld == 0 && ldc.parts.s == 1u)
    {
        ft_strcpy(fbuf, "-0.0");
        return (1);
    }
    else if (ld == 0 || ld == LDBL_MIN)
    {
        ft_strcpy(fbuf, "0.0");
        return (1);
    }
    else if (ld == -LDBL_MIN)
    {
        ft_strcpy(fbuf, "-0.0");
        return (1);
    }
    else if (is_inf(ldc))
    {
        ft_strcpy(fbuf, "inf");
        return (1);
    }
    else if (is_ninf(ldc))
    {
        ft_strcpy(fbuf, "-inf");
        return (1);
    }
    else if (is_nan(ldc))
    {
        ft_strcpy(fbuf, "nan");
        return (1);
    }

    return (0);
}

void    ft_dtoa(long double ld, char *buffer)
{
    char *int_part_buf;
    char *float_part_buf;
    int flag;
    t_ldc ldc;


    ldc = (t_ldc) {.ld = ld};
    if (is_reserved_value(ldc, ld, buffer))
        return;
    if (ldc.parts.e >= EXP_SHIFT)
    {

        ldc.parts.e = ldc.parts.e - EXP_SHIFT;
        int_part_buf = ft_memalloc(MAX_FLOAT_BUFF_SIZE);
        get_long_int_part(ldc.parts.m, ldc.parts.e, int_part_buf);
        flag = 1;
    }
    else
    {
        ldc.parts.e = EXP_SHIFT - ldc.parts.e;
        int_part_buf = ft_strdup("0");
        flag = 0;
    }
    if (ldc.parts.e < 63u || flag == 0)
    {
        float_part_buf = ft_memalloc(MAX_FLOAT_BUFF_SIZE);
        get_float_part(ldc.parts.m, ldc.parts.e, float_part_buf, flag);
    }
    else
        float_part_buf = ft_strdup("0");
    if (ld < 0)
        buffer[0] = '-';
    ft_strcat(buffer, int_part_buf);
    ft_strcat(buffer, ".");
    ft_strcat(buffer, float_part_buf);
    free(int_part_buf);
    free(float_part_buf);
}

