//
// Created by Aletha Yellin on 29/11/2019.
//

#ifndef PRINTF_GET_HEX_H
#define PRINTF_GET_HEX_H

size_t get_hex(va_list vargs, t_spec *spec, char *buffer);

size_t get_hex_l(va_list vargs, t_spec *spec, char *buffer);

size_t get_hex_h(va_list vargs, t_spec *spec, char *buffer);

size_t get_hex_hh(va_list vargs, t_spec *spec, char *buffer);

size_t get_hex_ll(va_list vargs, t_spec *spec, char *buffer);

#endif //PRINTF_GET_HEX_H
