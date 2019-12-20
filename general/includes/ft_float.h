//
// Created by dan on 20.12.19.
//

#ifndef PRINTF_FT_FLOAT_H
#define PRINTF_FT_FLOAT_H


typedef struct s_float
{
	long double		ld;
	double			d;
	int				is_up;
	unsigned long	exp;
	unsigned long	man;
	int				sign;

}				t_float;


void init_float(t_float *f);


#endif //PRINTF_FT_FLOAT_H
