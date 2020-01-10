//
// Created by Aletha Yellin on 20/11/2019.
//

#ifndef PRINTF_SPEC_FORMAT_PARSER_H
#define PRINTF_SPEC_FORMAT_PARSER_H

#include "ft_printf.h"
#include "color_settings.h"
#include "printf_constatns.h"
#include "size_parser.h"
#include "precision_parser.h"
#include "type_parser.h"
#include "width_parser.h"
#include "flags_parse.h"
#include "color_settings.h"



int     get_spec_format_length(const char *format);

t_spec	*parse_spec_format(const char *spc_fmt);

void	fill_spec_from_vargs(t_spec *spec, va_list *vargs);

#define MINUS_FLAG_ID 0
#define PLUS_FLAG_ID  1
#define WHITESPACE_FLAG_ID 2
#define OCTOTHORP_FLAG_ID 3
#define ZERO_FLAG_ID 4

#endif //PRINTF_SPEC_FORMAT_PARSER_H
