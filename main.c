#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include "gnl/get_next_line.h"

void test_gnl(int fd) {
//	printf("fd = %d\n", fd);
	int r;
	do {
    	char *s;
	 	r = get_next_line(fd, &s);
	    printf("%d|%s$\n", r, s);
    	free(s);
	} while(r > 0);
//	printf ("close == %d\n", close(fd));
}
int main(int ac, char *av[]) {
	int	fd = 0;
	int	i = 0;
	if (ac == 1)
		test_gnl(fd);
	else if (ac > 1) {
		test_gnl(INT_MAX);
		while (++i < ac) {
			fd = open(av[i], O_RDONLY);        	
		    printf("%s\n", av[i]);
		    test_gnl(fd);
		    printf("----------------------\n");
		}
	}
    return (0);
}
