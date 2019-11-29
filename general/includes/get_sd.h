//
// Created by Aletha Yellin on 29/11/2019.
//

#ifndef PRINTF_GET_DIGITS_FUNCS_H
#define PRINTF_GET_DIGITS_FUNCS_H

size_t get_sd(va_list vargs, t_spec *spec, char *buffer);

size_t get_sl(va_list vargs, t_spec *spec, char *buffer);

size_t get_sh(va_list vargs, t_spec *spec, char *buffer);

size_t get_shh(va_list vargs, t_spec *spec, char *buffer);

size_t get_sll(va_list vargs, t_spec *spec, char *buffer);

#endif //PRINTF_PRINT_GET_DIGITS_FUNCS_H