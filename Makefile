SRC		= get_next_line.c
MAIN	= main.c
OBJ		= $(SRC:.c=.o)
CC		= clang
CFLAGS	= -g -Wall -Wextra -Werror -D BUFFER_SIZE=3 -fsanitize=address -fno-omit-frame-pointer
NAME	= aa

$(NAME)	: $(OBJ) $(MAIN) Makefile
	cd gnl
	$(CC) $(CFLAGS) -o $@ $(MAIN) $(OBJ)
	cd ..

all		: $(NAME)

%.o		: %.c Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

clean	:
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all
