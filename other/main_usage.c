//
// Created by Aletha Yellin on 06/11/2019.
//

#include <stdio.h>
#include <limits.h>
#include <includes/ft_float.h>
#include "ft_float.h"

int main()
{

	double a;

	a = 123.45;
	printf("double = %E\n", a);
	float_cast cast = {.f = a};

	printf("sign = %d\n", cast.parts.sign);
    printf("mantissa = %d\n", cast.parts.mantisa);
    printf("exponent = %d\n", cast.parts.exponent);
	return (0);
}