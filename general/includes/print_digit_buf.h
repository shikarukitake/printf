//
// Created by dan on 1/15/20.
//

#ifndef PRINTF_PRINT_DIGIT_BUF_H
#define PRINTF_PRINT_DIGIT_BUF_H

#include "specificator.h"
#include "printf_constants.h"
#include "libft.h"
#include "print_d_buf.h"

typedef int (*t_put_prefix) (const char *, t_spec *, char *dest);

#define IS_SIGN(x) (x ? 1 : 0)

int         print_sign(char sign);

size_t print_buf(const char *buf);

int			print_digit_buf(char *digit, t_spec *spec, t_put_prefix pp);

int         print_sd_buf(char *digit, t_spec *spec, t_put_prefix pp);

int			print_d_buf(char *digit, t_spec *spec, t_put_prefix pp);

char        get_sign(char *digit, t_spec *spec);

#endif //PRINTF_PRINT_DIGIT_BUF_H
