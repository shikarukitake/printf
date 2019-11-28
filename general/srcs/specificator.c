//
// Created by Aletha Yellin on 25/11/2019.
//

#include "ft_printf.h"
#include <stdlib.h>

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
	new->precision.value = -1;
	while (i < MAX_FLAGS)
		new->flags[i++] = FALSE;
	return (new);
}