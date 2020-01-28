/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_buffered_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:45:40 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 16:47:02 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_OUTPUT_BUFF_SIZE 10000

#include "put_bch.h"
#include <unistd.h>

static int	g_was_init;

char		g_printf_buffer[MAX_OUTPUT_BUFF_SIZE];

static int	g_buf_size;

int			flush_buffer(void)
{
	int count;

	count = write(1, g_printf_buffer, g_buf_size);
	g_was_init = 0;
	g_buf_size = 0;
	return (count);
}

void		init(void)
{
	ft_bzero(g_printf_buffer, MAX_OUTPUT_BUFF_SIZE);
	g_was_init = 1;
}

int			put_bch(char ch)
{
	int count;

	count = 0;
	if (!g_was_init)
		init();
	if (g_buf_size < MAX_OUTPUT_BUFF_SIZE)
		g_printf_buffer[g_buf_size++] = ch;
	else
	{
		count = flush_buffer();
		count++;
		ft_putchar(ch);
	}
	return (count);
}

size_t		put_bstr(char *s)
{
	size_t i;
	size_t all;

	i = 0;
	all = 1;
	while (i < ft_strlen(s))
		all = put_bch(s[i++]);
	return (all);
}
