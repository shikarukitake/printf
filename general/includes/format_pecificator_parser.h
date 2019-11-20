//
// Created by Aletha Yellin on 20/11/2019.
//

#ifndef PRINTF_FORMAT_PECIFICATOR_PARSER_H
#define PRINTF_FORMAT_PECIFICATOR_PARSER_H

#include "util.h"

int		get_format_spec_length(const char *format);

typedef		struct	s_width
{
	int		value;
	t_bool	is_asterisk;

}					t_width;

typedef		struct	s_percision
{
	int		value;
	t_bool	is_asterisk;

}					t_precision;

typedef		struct	s_spec
{
	t_bool	flags[5];
	char	type;
	t_width	width;
	t_precision precision;

}					t_spec;



#define MINUS_FLAG_ID 0
#define PLUS_FLAG_ID  1
#define WHITESPACE_FLAG_ID 2
#define OCTOTHORP_FLAG_ID 3
#define ZERO_FLAG_ID 4

#endif //PRINTF_FORMAT_PECIFICATOR_PARSER_H
