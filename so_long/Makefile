CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

NAME = so_long

SRCS = 	get_next_line.c\
		get_next_line_utils.c\
		map_parsing.c\

%.o: %.c
	$(CC) -Imlx -c $< -o $@

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L. -lmlx -framework OpenGL -framework AppKit -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
