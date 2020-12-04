/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 23:46:20 by CWatcher          #+#    #+#             */
/*   Updated: 2020/12/04 20:28:21 by CWatcher         ###   ########.fr       */
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
	ssize_t			i;
	size_t			j;

	if (fd < 0 || !ln)
	{
		b.p = b.dat;
		b.n = 0;
		return (-1);
	}
	if (f != fd)
	{
		b.p = b.dat;
		b.n = 0;
		f = fd;
	}
	s.n = 0;
	if (!(s.p = malloc(sizeof(*s.p))))
		return (-1);
	*s.p = '\0';
	*ln = NULL;
	while (0 < b.n || 0 < (b.n = read(f, b.dat, BUFFER_SIZE)))
	{
		i = 0;
		while (i < b.n && b.p[i] != '\n')
			i++;
		if (!(*ln = malloc(s.n + i + 1)))
		{
			free(s.p);
			return (-1);
		}
		j = 0;
		while (j < s.n)
		{
			(*ln)[j] = s.p[j];
			j++;
		}
		free(s.p);
		s.p = *ln;
		j = -1;
		while (++j < (size_t)i)
			s.p[s.n + j] = *(b.p++);
		s.n += i;
		s.p[s.n] = '\0';
		if (i < b.n)
		{
			if ((b.n -= i + 1))
				b.p++;
			else
				b.p = b.dat;
			return (1);
		}
		else
		{
			b.p = b.dat;
			b.n = 0;
		}
	}
	if (b.n == 0)
		*ln = s.p;
	return (b.n);
}
