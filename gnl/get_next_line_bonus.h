/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 01:19:41 by CWatcher          #+#    #+#             */
/*   Updated: 2020/12/10 00:22:39 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>
# include <sys/types.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef FD_MAX
#  define FD_MAX 255
# endif

# if BUFFER_SIZE == 0 || FD_MAX == 0
#  error "ISO C forbids zero-size array"
# endif

int				get_next_line(int fd, char **ln);

typedef	struct	s_buffer
{
	char		dat[BUFFER_SIZE + 1];
	ssize_t		i;
	ssize_t		n;
}				t_buffer;

typedef	struct	s_str
{
	char		*p;
	size_t		n;
}				t_str;

#endif
