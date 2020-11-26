#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "gnl/get_next_line.h"

int main(int ac, char *av[]) {
    char *s;
	int fd = 0;
	if (ac > 1)
		fd = open(av[1], O_RDONLY);
	if (fd < 0) {
		printf("файл не открылся");
		return -1;
	}
	printf("fd = %d\n", fd);
	int g;
	do {
	 	g = get_next_line(fd, &s); 
	    printf("%s$\n", s);
    	free(s);
	} while(g);
    return (0);
}
