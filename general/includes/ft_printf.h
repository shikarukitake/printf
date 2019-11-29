//
// Created by Aletha Yellin on 06/11/2019.
//

#ifndef PRINTF_FT_PRINTF_H
#define PRINTF_FT_PRINTF_H

# include <stdarg.h>

# include "libft.h"
# include "printf_constatns.h"
# include "basic_funcs.h"
# include "additional_funcs.h"
# include "util.h"
# include "additional_funcs.h"
# include "type_func_table.h"
# include "specificator.h"
# include "spec_format_parser.h"
# include "fill_flags.h"
# include "width_parser.h"
# include "precision_parser.h"
# include "size_parser.h"
# include "type_parser.h"
# include "common_print_funcs.h"
# include "print_sd_func_table.h"
# include "print_sd_funcs.h"
# include "basic_conversion_funcs.h"
# include "get_sd_func_table.h"
# include "get_sd_funcs.h"

int		ft_printf(const char *format, ...);

#endif //PRINTF_FT_PRINTF_H
