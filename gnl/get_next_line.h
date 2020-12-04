/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 01:19:41 by CWatcher          #+#    #+#             */
/*   Updated: 2020/12/04 01:20:27 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int				get_next_line(int fd, char **ln);

typedef	struct	s_buffer
{
	char		dat[BUFFER_SIZE];
	char		*p;
	ssize_t		n;
}				t_buffer;

typedef	struct	s_str
{
	char		*p;
	size_t		n;
}				t_str;

#endif
