CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

INCLUDE = -lpthread

SRCS = main.c\
	make_default.c\
	philosophers.c\
	utils.c

OBJS = $(SRCS:.c=.o)

NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJS)

clean: 
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all