SRC		= ~/wrk/2gnl/gnl/get_next_line.c
MAIN	= main.c
OBJ		= $(SRC:.c=.o)
CC		= cc
CFLAGS	= -g -Wall -Wextra -Werror #-D BUFFER_SIZE=32
NAME	= aa

$(NAME)	: $(OBJ) $(MAIN) Makefile
	$(CC) $(CFLAGS) -o $@ $(MAIN) $(OBJ)

all		: $(NAME)

%.o		: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean	:
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all
