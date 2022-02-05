SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

CPP = c++
FLAG = -Werror -Wall -Wextra

NAME = megaphone

$(NAME): $(OBJS)
	$(CPP) $(FLAG) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re