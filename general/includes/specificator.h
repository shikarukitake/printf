//
// Created by Aletha Yellin on 22/11/2019.
//
#ifndef PRINTF_SPECIFICATOR_H
#define PRINTF_SPECIFICATOR_H

#include "util.h"
#include "print_settings.h"
#include <stdlib.h>

typedef		struct	s_width
{
	int		value;
	t_bool	is_asterisk;
}					t_width;

typedef		struct	s_percision
{
	int		value;
	t_bool	is_asterisk;
	t_bool	is_dot;

}					t_precision;

typedef 	struct	s_size
{
	int		id;
	char	value[3];
}					t_size;

#define MAX_FLAGS 255

typedef		struct	s_spec
{
	t_bool              flags[MAX_FLAGS];
	char                type;
	t_width             width;
	t_precision         precision;
	t_size              size;
	t_print_settings    settings;

}					t_spec;

t_spec	*init_spec();

#endif //PRINTF_SPECIFICATOR_H
