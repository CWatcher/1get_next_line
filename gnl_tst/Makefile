DIR		= ../get_next_line
SRC		= $(DIR)/get_next_line.c
OBJ		= $(SRC:.c=.o)
MAIN	= main.c
CFLAGS	= -g -Wall -Wextra -Werror -D BUFFER_SIZE=9 -I$(DIR)
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
