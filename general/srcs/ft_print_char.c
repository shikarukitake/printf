//
// Created by Aletha Yellin on 25/12/2019.
//

#include "ft_print_char.h"

#define PREFIX1  128
#define PREFIX2  192
#define PREFIX3  224
#define PREFIX4  240

void    ft_put_oct4(wchar_t wchar)
{
    unsigned int buf[4];

    buf[0] = (wchar >> 18) + PREFIX4;
    buf[1] = ((wchar >> 12) & 63) + PREFIX1;
    buf[2] = ((wchar>> 6) & 63) + PREFIX1;
    buf[3] = (wchar & 63) +PREFIX1;
    write(1, buf, 4);
}

void    ft_put_oct3(wchar_t wchar)
{
    unsigned int buf[3];

    buf[0] = (wchar >> 12) + PREFIX3;
    buf[1] = ((wchar >> 6) & 63) + PREFIX1;
    buf[2] = (wchar & 63) + PREFIX1;
    write(1, buf, 3);
}

void    ft_put_oct2(wchar_t wchar)
{
    unsigned int buf[2];

    buf[0] = (wchar >> 6) + PREFIX2;
    buf[1] = (wchar & 63) + PREFIX1;
    write(1, buf, 2);
}

void    ft_putwchar(wchar_t wch)
{
    if (wch <= 127)
        ft_putchar(wch);
    else if (wch > 127 && wch <= 2047)
        ft_put_oct2(wch);
    else if (wch > 2047 && wch < 65535)
        ft_put_oct3(wch);
    else if (wch > 65535 && wch < 1114111)
        ft_put_oct4(wch);
}
