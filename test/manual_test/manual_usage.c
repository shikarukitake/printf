//
// Created by dan on 1/11/20.
//

#include "ft_printf.h"
#include <float.h>
#include <string.h>


int main()
{
    double number;

    number = 59.999999;
    ft_printf("%e\n", number);
    printf("%e\n", number);

//    number = 52.9999;
//    ft_printf("%.20e\n", number);
//    printf("%.20e\n", number);
}