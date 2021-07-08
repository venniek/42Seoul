
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

NAME = so_long

SRCS = main.c

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) -L./minilibx_mms_20210621 -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
