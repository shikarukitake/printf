//
// Created by Aletha Yellin on 22/11/2019.
//
#ifndef PRINTF_SPECIFICATOR_H
#define PRINTF_SPECIFICATOR_H

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

t_spec	*init_spec();

#endif //PRINTF_SPECIFICATOR_H