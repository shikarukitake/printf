//
// Created by Aletha Yellin on 20/11/2019.
//

#include "print_other.h"

int	ft_print_empty(t_spec *spec, va_list *args)
{
	((void)spec);
	((void)args);
	return (0);
}

int	ft_print_percent(t_spec *spec, va_list *args)
{
    int i;

    i = 0;
	(void)(args);
    if (spec->flags['-'] == TRUE)
    {
        ft_putchar('%');
        i++;
        while (i < spec->width.value)
        {
            ft_putchar(' ');
            i++;
        }
    }
    else
    {
        while (i < spec->width.value - 1)
        {
            ft_putchar(' ');
            i++;
        }
        ft_putchar('%');
        i++;
    }
	return (i);
}

int	ft_print_color(t_spec *spec, va_list *args)
{
    ((void)spec);
    ((void)args);
    return (6);
}