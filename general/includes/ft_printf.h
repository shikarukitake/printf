//
// Created by Aletha Yellin on 06/11/2019.
//

#ifndef PRINTF_FT_PRINTF_H
#define PRINTF_FT_PRINTF_H

# include <stdarg.h>

# include "printf_constatns.h"
# include "basic_print.h"
# include "util.h"
# include "additional_print.h"
# include "type_func_table.h"
# include "specificator.h"
# include "spec_format_parser.h"
# include "fill_flags.h"
# include "width_parser.h"
# include "precision_parser.h"
# include "size_parser.h"
# include "type_parser.h"
# include "common_print.h"
# include "get_sd.h"
# include "convert.h"
# include "get_hex.h"
# include "get_digit.h"
# include "get_hex.h"
# include "get_oct.h"
# include "print_oct.h"
# include "print_hex.h"
# include "get_ud.h"
# include "print_ud.h"
# include "get_p.h"
# include "float_print.h"

//TODO: write right #include to all .c files

int		ft_printf(const char *format, ...);

#endif //PRINTF_FT_PRINTF_H
