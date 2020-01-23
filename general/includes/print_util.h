//
// Created by Aletha Yellin on 22/01/2020.
//

#ifndef PRINTF_PRINT_UTIL_H
# define PRINTF_PRINT_UTIL_H

# include "specificator.h"
# include "libft.h"
# include "spec_util.h"
# include "float_util.h"
# include "print_oct_buf.h"

int		fill_precision_field(char *buf, t_spec *spec);

int		fill_w_field(int i, t_spec *spec, char sign, int prefix);

int		print_sign(char sign);

char	get_sign(char *digit, t_spec *spec);

#endif //PRINTF_PRINT_UTIL_H
