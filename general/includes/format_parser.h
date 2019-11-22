//
// Created by Aletha Yellin on 20/11/2019.
//

#ifndef PRINTF_FORMAT_PARSER_H
#define PRINTF_FORMAT_PARSER_H

#include "util.h"

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

typedef 	struct	s_size
{
	int id;
	char value[3];
}					t_size;

#define MAX_FLAGS 5

typedef		struct	s_spec
{
	t_bool		flags[MAX_FLAGS];
	char		type;
	t_width		width;
	t_precision precision;
	t_size		size;

}					t_spec;

int		get_format_spec_length(const char *format);

t_spec	*parse_format(const char *format);

#define MINUS_FLAG_ID 0
#define PLUS_FLAG_ID  1
#define WHITESPACE_FLAG_ID 2
#define OCTOTHORP_FLAG_ID 3
#define ZERO_FLAG_ID 4

#endif //PRINTF_FORMAT_PARSER_H
