#include "stdlib.h"
#include "unistd.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif
typedef struct
{
	char	dat[BUFFER_SIZE];
	char	*p;
	ssize_t	n;
	int		fd;
} t_buffer;

typedef struct {
	char*	p;
	size_t	n;
} t_str;

int get_next_line(int fd, char **line)
{
	static	int f = -2;
    static	t_buffer b;
	static	t_str	s;
	size_t	i;

	if (fd < 0)
		return (-1);
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
	*line = NULL;
	while (0 < b.n || 0 < (b.n = read(f, b.dat, BUFFER_SIZE)))
	{
		if (!(*line = malloc(b.n + 1)))
		{
			free(s.p);
			return (-1);
		}
		i = -1;
		while (++i < s.n)
			(*line)[i] = s.p[i];
		free(s.p);
		while(b.n && b.n-- && *(b.p++) != '\n')
			(*line)[i++] = *(b.p - 1);
		s.p = *line;
		s.p[i] = '\0';
		s.n = i;
		if (*(b.p - 1) == '\n')
		{
			if (!b.n)
				b.p = b.dat;
			return (1);
		}
		else
			b.p = b.dat;
	}
	if (b.n == 0)
		*line = s.p;
    return (b.n);
}
