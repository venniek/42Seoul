CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

NAME = so_long

SRCS = 	srcs/get_next_line.c\
		srcs/get_next_line_utils.c\
		srcs/map_parsing.c\
		srcs/main.c\
		srcs/error.c\
		srcs/utils.c

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
