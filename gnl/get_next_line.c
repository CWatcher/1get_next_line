/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 23:46:20 by CWatcher          #+#    #+#             */
/*   Updated: 2020/12/07 00:11:46 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	get_next_line(int fd, char **ln)
{
	static int		f = -2;
	static t_buffer b;
	static t_str	s;
	size_t			j;

	if (!ln)
		return (-1);
	if (f != fd)
	{
		b.p = b.dat;
		b.n = 0;
		f = fd;
	}
	s.n = 0;
	*ln = NULL;
	while (0 < b.n || 0 < (b.n = read(f, b.dat, BUFFER_SIZE)))
	{
		if (!(s.p = malloc(s.n + b.n + 1)))
			return (-1);
		j = -1;
		while (++j < s.n)
			s.p[j] = (*ln)[j];
		free(*ln);
		*ln = s.p;
		j = 0;
		while (j < (size_t)b.n && *b.p != '\n')
			s.p[s.n + j++] = *b.p++;
		b.p++;
		s.n += j;
		s.p[s.n] = '\0';
		if ((b.n -= j) <= 1)
			b.p = b.dat;
		if (b.n && (--b.n || (b.p = b.dat)))
			return (1);
	}
	if (*ln || b.n)
		return (b.n);
	if ((*ln = malloc(sizeof(**ln))))
		**ln = '\0';
	return (*ln ? 0 : -1);
}
