CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

INCLUDE = -lpthread

SRCS = start.c\
	make_default.c\
	utils.c\
	phils_act.c\
	threads.c

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