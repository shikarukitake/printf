//
// Created by Aletha Yellin on 20/11/2019.
//

#ifndef PRINTF_SPEC_FORMAT_PARSER_H
#define PRINTF_SPEC_FORMAT_PARSER_H

#include "ft_printf.h"

ssize_t	get_spec_format_length(const char *format);

t_spec	*parse_spec_format(const char *spc_fmt);

#define MINUS_FLAG_ID 0
#define PLUS_FLAG_ID  1
#define WHITESPACE_FLAG_ID 2
#define OCTOTHORP_FLAG_ID 3
#define ZERO_FLAG_ID 4

#endif //PRINTF_SPEC_FORMAT_PARSER_H
