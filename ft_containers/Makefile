SRCS = test_map.cpp

CPP = c++
FLAG = -Werror -Wall -Wextra -g -std=c++98

NAME = FT_containers

$(NAME): $(SRCS)
	$(CPP) $(FLAG) -o $(NAME) $(SRCS)

all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re