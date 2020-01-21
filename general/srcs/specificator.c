//
// Created by Aletha Yellin on 25/11/2019.
//

#include "specificator.h"


t_spec	*init_spec()
{
	t_spec	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(t_spec));
	if (!new)
		return (NULL);
	new->type = -1;
	new->size.id = -1;
	new->width.value = -1;
	new->width.is_asterisk = FALSE;
	new->precision.value = -1;
	new->precision.is_asterisk = FALSE;
	new->precision.is_dot = FALSE;
	while (i < MAX_FLAGS)
		new->flags[i++] = FALSE;
	new->color_id = -1;
	return (new);
}