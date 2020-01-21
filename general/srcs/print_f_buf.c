//
// Created by Aletha Yellin on 29/11/2019.
//

#include "print_f_buf.h"

void change_first_digits(char *buf)
{
    char tmp[MAX_FLOAT_BUFF_SIZE];

    ft_strcpy(tmp , buf);
    if (tmp[0] != '-')
    {
        ft_strcpy(buf, "10");
        ft_strcat(buf, tmp + 1);
    }
    else
    {
        ft_strcpy(buf, "-10");
        ft_strcat(buf, tmp + 2);
    }
}

void    round_int_part(char *buf)
{
    int i;

    i = ft_strchri(buf, '.');
    if (buf[i - 1] < '9')
        buf[i - 1] += 1;
    else
    {
        buf[i - 1] = '0';
        i--;
        while (i > 0 && buf[i] == '9') {
            buf[i] = '0';
            i--;
        }
        if (i == 0 && buf[i + 1] == '0')
            change_first_digits(buf);
    }
}

int is_special_value(char *buf)
{
    return (ft_strcmp(buf, "inf") == 0 || ft_strcmp(buf, "-inf") == 0 ||
            ft_strcmp(buf, "nan") == 0);
}

void    round_float(char *buf, int precision)
{
    int dot;
    int i;
    int last;


    dot = ft_strchri(buf, '.');
    i = dot + precision + 1;
    buf[i + 1] = '\0';
    last = i;
    if (buf[i] > '4' && buf[i - 1] != '.' )// && (buf[i - 1] - '0') % 2 != 0)
    {
        i--;
        if (buf[i] != '9')
            buf[i] += 1;
        else if (buf[i] == '9')
        {
            buf[i--] = '0';
            while (buf[i] == '9')
            {
                buf[i] = '0';
                i--;
            }
            if (buf[i] != '.')
                buf[i] += 1;
            else
                round_int_part(buf);
        }
        buf[last] = '\0';
        return ;
    }
    if (buf[i] > '4' && buf[i - 1] == '.')
        round_int_part(buf);
    buf[last] = '\0';
}


int is_float_null_case(char *f, t_spec *spec)
{

    if (ft_strcmp(f, "0.0") == 0 && spec->precision.value <= 0 && spec->precision.is_dot == TRUE)
    {
        ft_putchar('0');
        return (1);
    }
    return (0);
}

char get_float_fill_ch(int len, t_spec *spec)
{
    len = 0;
    if(spec->flags['0'] == TRUE && spec->flags['-'] == FALSE)
        return '0';
    else
        return ' ';
}

int fill_float_width_field(int i, t_spec *spec)
{
    char	ch;
    int		len;

    len = i;
    ch = get_float_fill_ch(i, spec);
    while (i < spec->width.value)
    {
        ft_putchar(ch);
        i++;
    }
    return (i - len);
}

int fill_float_sign_width_field(int i, t_spec *spec, char sign)
{
    char	ch;
    int		len;

    len = i;
    ch = get_float_fill_ch(i + IS_SIGN(sign), spec);
    while (i + IS_SIGN(sign) < spec->width.value)
    {
        ft_putchar(ch);
        i++;
    }
    return (i - len);
}

int print_float_buf(char *f, t_spec *spec)
{
   int i;

   i = 0;
   while (f[i] != '.')
   {
       ft_putchar(f[i]);
       i++;
   }
   if (spec->precision.value != 0)
   {
       ft_putstr(f + i);
       i = ft_strlen(f);
   }
   if (spec->precision.value == 0 && spec->flags['#'] == TRUE)
   {
       ft_putchar('.');
       i++;
   }
   return (i);
}

int get_float_precision(t_spec *spec)
{
    return (spec->precision.value == -1 ? 6 : spec->precision.value);
}

void add_zeros(char *buf, t_spec *spec)
{
    int i;
    int f_num;
    int precision;

    precision = get_float_precision(spec);
    f_num = 0;
    i = (int)ft_strchri(buf, '.') + 1;
    while (buf[i])
    {
        f_num++;
        i++;
    }
    while (f_num < precision)
    {
        buf[i++] = '0';
        f_num++;
    }
    buf[i] = '\0';
}

void add_sing_and_sp(char *f, t_spec *spec)
{
    if (ft_strcmp(f, "inf") == 0 && spec->flags['+'] == TRUE)
    {
        ft_strcpy(f, "+inf");
        if (spec->flags[' '] == TRUE)
          ft_strcpy(f, " +inf");
        return;
    }
    else if (ft_strcmp(f, "inf") == 0 && spec->flags[' '] == TRUE)
        ft_strcpy(f, " inf");
}

t_ui shift(char *buf, t_exp e, t_spec *spec)
{
    t_ui     count_int;

    count_int = 0;
    if ((t_ull) e.value == 0)
        count_int = 0;
    else
        while (buf[count_int + 1] != '.')
            count_int++;
    if (spec->flags['-'] == TRUE)
        count_int--;
    return count_int;
}

void    transform_to_e(char *buf, t_exp e, t_spec *spec, t_ui count_int)
{
    char swap[ft_strlen(buf)];
    t_ui count;

    ft_bzero(swap, ft_strlen(buf));
    count = 0;
    if (spec->flags['-'] == TRUE)
        swap[count++] = '-';
    swap[count] = buf[count];
    swap[++count] = '.';
    while (count_int != 0)
    {
        swap[count + 1] = buf[count];
        count++;
        count_int--;
    }
    ft_strncat(swap, buf + count + 1, ft_strlen(buf) - count);
    ft_strcpy(buf, swap);


}

void    shift_to_int_part(char *buf, t_exp e, t_spec *spec, t_ui pow)
{
    char    swap[ft_strlen(buf)];
    size_t  count;
    int  precision;

    count = 0;
    precision = spec->precision.value == -1 ? 6 : spec->precision.value + 2;
    if (e.value - (t_ull)e.value > 0 && (t_ull)e.value == 0)
    {
        while (*buf == '0' || *buf == '.')
            buf++;
//        while
//        swap[count++] = *buf++;
        swap[count++] = *buf++;
    }
}

int	print_f_buf(char *f, t_spec *spec, t_exp e)
{
    int 	i;
    char    sign;
    int		is_dot;
    t_ui    pow;

    i = 0;
    if (is_special_value(f))
    {
        add_sing_and_sp(f, spec);
        return (print_str(f, spec));
    }
    if (is_float_null_case(f, spec))
        return (1);
    pow = shift(f, e, spec);
    transform_to_e(f, e, spec, pow);
    round_float(f, (spec->precision.value == -1 ? 6 : spec->precision.value));
    add_zeros(f, spec);
//    shift_to_int_part(f, e, spec, pow);
//    add_eeeeee(f,)
    if (is_need_wh(f, spec))
    {
        ft_putchar(' ');
        spec->width.value--;
    }
    sign = get_sign(f, spec);
    is_dot = (f[ft_strlen(f) - 1] == '.');
    if (spec->flags['-'] == TRUE)
    {
        i += print_sign(sign);
        i += print_float_buf(f, spec);
        i += fill_float_width_field(i, spec);
    }
    else
    {
        if (get_float_fill_ch((int)ft_strlen(f) + IS_SIGN(sign), spec) == ' ')
        {
            i += fill_float_sign_width_field(ft_strlen(f) - is_dot, spec, sign);
            i += print_sign(sign);
        }
        else
        {
            i += print_sign(sign);
            i += fill_float_sign_width_field(ft_strlen(f) - is_dot, spec, sign);
        }
        i += print_float_buf(f, spec);
    }
    if (is_need_wh(f, spec) && !IS_SIGN(sign))
        i++;
    return (i);
}