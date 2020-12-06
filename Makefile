SRC		= ~/wrk/2gnl/gnl/get_next_line.c
MAIN	= main.c
OBJ		= $(SRC:.c=.o)
CC		= clang
CFLAGS	= -g -Wall -Wextra -Werror -D BUFFER_SIZE=9 -fsanitize=address -fno-omit-frame-pointer
NAME	= aa

$(NAME)	: $(OBJ) $(MAIN) Makefile
	$(CC) $(CFLAGS) -o $@ $(MAIN) $(OBJ)

all		: $(NAME)

%.o		: %.c Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

clean	:
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all
