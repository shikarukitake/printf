/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <ayellin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:43:17 by ayellin           #+#    #+#             */
/*   Updated: 2019/09/30 08:38:19 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

static int		line_make(const int fd, char **all, char **line)
{
	char	*temp;
	int		len;

	if (ft_strchr(all[fd], '\n'))
	{
		len = ft_strchri(all[fd], '\n');
		*line = ft_strsub(all[fd], 0, len);
		temp = ft_strsub(all[fd], len + 1, ft_strlen(all[fd]) - len);
		free(all[fd]);
		all[fd] = ft_strdup(temp);
		free(temp);
	}
	else
	{
		*line = ft_strdup(all[fd]);
		ft_strdel(&all[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*all[OPEN_MAX];
	char			buff[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = 0;
		if (all[fd] == NULL)
			all[fd] = ft_strnew(1);
		if (!(all[fd] = ft_strjoinf(all[fd], buff, 1)))
			return (-1);
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && (all[fd] == NULL || all[fd][0] == '\0'))
		return (0);
	return (line_make(fd, all, line));
}
