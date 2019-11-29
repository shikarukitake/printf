//
// Created by Aletha Yellin on 29/11/2019.
//

#ifndef PRINTF_PRINT_SD_FUNCS_H
#define PRINTF_PRINT_SD_FUNCS_H

size_t print_sd(va_list vargs, t_spec *spec, char *buffer);

size_t print_sl(va_list vargs, t_spec *spec, char *buffer);

size_t print_sh(va_list vargs, t_spec *spec, char *buffer);

size_t print_shh(va_list vargs, t_spec *spec, char *buffer);

size_t print_sll(va_list vargs, t_spec *spec, char *buffer);

#endif //PRINTF_PRINT_SD_FUNCS_H
