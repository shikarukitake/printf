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

int			print_digit_buf(char *digit, t_spec *spec, t_put_prefix pp);

int         print_sd_buf(char *digit, t_spec *spec, t_put_prefix pp);

int			print_d_buf(char *digit, t_spec *spec, t_put_prefix pp);

#endif //PRINTF_PRINT_DIGIT_BUF_H
