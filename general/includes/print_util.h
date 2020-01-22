//
// Created by Aletha Yellin on 22/01/2020.
//

#ifndef PRINTF_PRINT_UTIL_H
# define PRINTF_PRINT_UTIL_H

# include "specificator.h"
# include "libft.h"
# include "spec_util.h"

int		fill_precision_field(char *buf, t_spec *spec);

int		fill_width_field(int i, t_spec *spec);

int		print_sign(char sign);

char	get_sign(char *digit, t_spec *spec);

#endif //PRINTF_PRINT_UTIL_H
