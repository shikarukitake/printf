//
// Created by Aletha Yellin on 21/01/2020.
//

#ifndef PRINTF_LONG_ARITHMETIC_H
#define PRINTF_LONG_ARITHMETIC_H

void		multiply_by_2(char *buf, int size, unsigned n);

void		long_sum(char *to_sum, char *result, int n, int direct);

void		divide_by_2(char *divided, int n);

void		rev_divide_by_2(char *divided, int n);

int    sum_direct_long(char *divided, char *result, int n);

int    sum_reverse_int(char *to_sum, char *result, int n);

#endif //PRINTF_LONG_ARITHMETIC_H
