/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 23:46:20 by CWatcher          #+#    #+#             */
/*   Updated: 2020/12/09 23:06:53 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	get_next_line(int fd, char **ln)
{
	static t_buffer	b[FD_MAX + 1];
	static t_str	s;
	size_t			j;

	if (!ln)
		return (-1);
	if (fd < 0 || fd > FD_MAX)
	{
		*ln = NULL;
		return (-1);
	}
	s.n = 0;
	*ln = NULL;
	while (0 < b[fd].n || 0 < (b[fd].n = read(fd, b[fd].dat, BUFFER_SIZE)))
	{
		if (!(s.p = malloc(s.n + b[fd].n + 1)))
			return (-1);
		j = -1;
		while (++j < s.n)
			s.p[j] = (*ln)[j];
		free(*ln);
		*ln = s.p;
		while (b[fd].n && b[fd].dat[b[fd].i++] != '\n' && b[fd].n--)
			s.p[s.n++] = b[fd].dat[b[fd].i - 1];
		s.p[s.n] = '\0';
		b[fd].i = b[fd].n > 1 ? b[fd].i : 0;
		if (b[fd].n && b[fd].n--)
			return (1);
	}
	if (!*ln && !b[fd].n && (*ln = *ln || b[fd].n ? *ln : malloc(sizeof(**ln))))
		**ln = '\0';
	return (*ln ? b[fd].n : -1);
}
