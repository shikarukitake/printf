//
// Created by dan on 20.12.19.
//

#ifndef PRINTF_FT_FLOAT_H
#define PRINTF_FT_FLOAT_H

#include <stdint.h>

typedef struct s_float
{
	long double		ld;
	double			d;
	int				is_up;
	unsigned long	exp;
	unsigned long	man;
	int				sign;

}				t_float;


typedef union {
    float f;
    struct {
        unsigned int mantisa : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;
    } parts;
} float_cast;


typedef union {
    double d;
    struct {
        unsigned long   mantisa : 52;
        unsigned int    exponent : 11;
        unsigned int    sign : 1;
    } parts;
} double_cast;


typedef union {
    long double ld;
    struct {
        unsigned long  mantisa : 64;
        unsigned int   exponent : 15;
        unsigned int   sign : 1;
    } parts;
} long_double_cast;

void init_float(t_float *f);


#endif //PRINTF_FT_FLOAT_H
