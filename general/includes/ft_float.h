//
// Created by dan on 20.12.19.
//

#ifndef PRINTF_FT_FLOAT_H
#define PRINTF_FT_FLOAT_H

#include <stdint.h>

typedef struct s_float
{
	long double		ld;
	int				is_up;
	unsigned long	exp;
	unsigned long	man;
	int				sign;

}				t_float;

typedef union {
    long double ld;
    struct {
        unsigned long  mantisa : 64;
        unsigned int   exponent : 15;
        unsigned int   sign : 1;
    } parts;
} long_double_cast;

void init_float(t_float *f);

void    ft_dtoa(long double ld, char *buffer);

#endif //PRINTF_FT_FLOAT_H
