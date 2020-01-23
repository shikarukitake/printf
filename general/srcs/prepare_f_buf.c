//
// Created by Aletha Yellin on 23/01/2020.
//

#include "prepare_f_buf.h"

void		add_sing_and_sp(char *f, t_spec *spec)
{
	if (ft_strcmp(f, "inf") == 0 && spec->flags['+'] == TRUE)
	{
		ft_strcpy(f, "+inf");
		if (spec->flags[' '] == TRUE)
			ft_strcpy(f, " +inf");
		return ;
	}
	else if (ft_strcmp(f, "inf") == 0 && spec->flags[' '] == TRUE)
		ft_strcpy(f, " inf");
}

void		add_zeros(char *buf, t_spec *spec)
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