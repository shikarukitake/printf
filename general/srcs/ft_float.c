//
// Created by dan on 20.12.19.
//

#include "ft_float.h"

void init_float(t_float *f)
{
	f->ld = 0.0;
	f->d = 0.0;
	f->exp = 0;
	f->is_up = 0;
	f->man = 0;
	f->sign = 0;
}