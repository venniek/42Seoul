CC = gcc
CFLAGS = -Werror -Wextra -Wall
RM = rm -f

NAME = pipex

INC = -I.

SRCS = test.c

%.o: %.c
	$(CC) $(INC) -c $< -o $@

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re pipex