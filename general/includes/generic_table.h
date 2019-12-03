//
// Created by Aletha Yellin on 29/11/2019.
//

#ifndef PRINTF_GENERIC_TABLE_H
#define PRINTF_GENERIC_TABLE_H

typedef struct s_convert_args
{
	int		is_signed;
	char	*(*i_convert)(int, char*, int, char);
	char 	*(*ll_convert)(long long, char *, int, char);
	int		base;
	char	a;
}				t_convert_args;

typedef void (*t_to_str_func)(va_list, t_convert_args, t_spec *, char *);

typedef struct s_to_str
{
	t_to_str_func	f;
	t_convert_args	args;

}				t_to_str;


#endif //PRINTF_GENERIC_TABLE_H
