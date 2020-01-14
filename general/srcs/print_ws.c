//
// Created by Aletha Yellin on 25/12/2019.
// TODO: put it to libft

#include "print_ws.h"

size_t ft_wstrlen(wchar_t *str)
{
    size_t l;

    l = 0;
    while (str[l])
        l++;
    return (l);
}

void    ft_putwstr(wchar_t *str)
{
    size_t i;

    i = 0;
    while (str[i])
    {
        ft_putwchar(str[i]);
        i++;
    }
}

int		ft_print_ws(t_spec* spec, va_list *args)
{
    wchar_t *tmp;
    int i;

    i = 0;
    tmp = va_arg(*args, wchar_t *);
    if (spec->precision.value == -1)
    {
        ft_putwstr(tmp);
        return (ft_wstrlen(tmp));
    }
    else
    {
        while (i < spec->precision.value)
        {
            ft_putwchar(tmp[i]);
            i++;
        }
        return (i);
    }
}