//
// Created by dan on 1/11/20.
//

#include "ft_printf.h"
#include <float.h>
#include <string.h>

void    mult_by_2(char *buf, int size, unsigned n)
{
    int carry;
    int i;
    int p;

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

void    transform(char *buf, char *new_buf, int n)
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

void   set_float_long_res(char *result, int i, int swap, int *int_part)
{
    if (swap < 10)
        result[i] = swap;
    else
    {
        result[i] = swap - 10;
        set_float_long_res(result, i + 1, result[i + 1] + 1, int_part);
    }
}

static void	ch_swap(char *a, char *b)
{
    char tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}


void    reverse(char *buf, int n)
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

char*   divide_float_by_2(char *divided, int n)
{
    int i;

    i = n - 1;
    if (divided[0] == 1 && divided[1] == 0)
    {
        divided[0] = 0;
        return (NULL);
    }
    //reverse(divided, n);
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
    //reverse(divided, n);
    return (divided);
}

int    sum_long_float_int(char *to_sum, char *result, int n)
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
            set_float_long_res(result, i, swap, &int_part);
        i++;
    }
    return int_part;
}

#define MAX_BUFF_SIZEE 10000
#define DBL_INF    0x7FF0000000000000
#define DBL_NINF   0xFFF0000000000000
#define DBL_NAN    0x7FF0000000100000
#define DBL_PZERO  0x0000000000000000
#define DBL_NZERO  0x8000000000000000

#define LDBL_INF   0x7FFF0000000000000000L
#define LDBL_NINF  0xFFFF0000000000000000L
#define LDBL_NAN   0x7FFF0000000001000000L
#define LDBL_PZERO 0x00000000000000000000L
#define LDBL_NZERO 0x80000000000000000000L

int main()
{
//    char buf3[MAX_BUFF_SIZEE];
//    char new_buf[MAX_BUFF_SIZEE];
//
//    bzero(new_buf, MAX_BUFF_SIZEE);
//    bzero(buf3, MAX_BUFF_SIZEE);
//
//    buf3[0] = 1;
//    mult_by_2(buf3, MAX_BUFF_SIZEE, 3);
//    divide_float_by_2(buf3, MAX_BUFF_SIZEE);
//    transform(buf3, new_buf, MAX_BUFF_SIZEE);
//
//    printf("32 / 2 = %s\n", new_buf);

//    double special;
//    *((unsigned long *)(&special)) = DBL_NAN;
//    ft_printf("% .7f\n", special);
        ft_printf("%.0Lf\n", LDBL_MAX);
        printf("%.0LF\n", LDBL_MAX);
//    printf("%f\n", (long double)DBL_NINF);
}