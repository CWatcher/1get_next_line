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
	ssize_t	i;
	size_t	j;
	//char	*p;

	if (fd < 0)
		return (-1);
	if (f != fd)
	{
		b.p = b.dat;
		b.n = 0;
		f = fd;
	}
	s.p = NULL;
	s.n = 0;
	while (0 < b.n || 0 < (b.n = read(f, b.dat, BUFFER_SIZE)))
	{
		i = 0;
		while(i < b.n && b.p[i] != '\n')
			i++;
		if (!(*line = malloc(s.n + i + 1)))
		{
			free(s.p);
			return (-1);
		}
		j = 0;
		while (j < s.n)
		{
			(*line)[j] = s.p[j];
			j++;
		}
		free(s.p);
		s.p = *line;
		j = -1;
		while (++j < (size_t)i)
			s.p[s.n + j] = *(b.p++);
		s.n += i;
		s.p[s.n] = '\0';
		b.n -= i + (i < b.n);
		if (!b.n)
			b.p = b.dat;
		else
			b.p++;
		if (i < b.n)
			return (1);
	}
    return (b.n);
}
