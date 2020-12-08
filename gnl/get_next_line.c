/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 23:46:20 by CWatcher          #+#    #+#             */
/*   Updated: 2020/12/09 00:37:36 by CWatcher         ###   ########.fr       */
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
		while (b.n && *b.p++ != '\n' && b.n--)
			s.p[s.n++] = *(b.p - 1);
		s.p[s.n] = '\0';
		b.p = b.n > 1 ? b.p : b.dat;
		if (b.n && b.n--)
			return (1);
	}
	if (!*ln && !b.n && (*ln = *ln || b.n ? *ln : malloc(sizeof(**ln))))
		**ln = '\0';
	return (*ln ? b.n : -1);
}
