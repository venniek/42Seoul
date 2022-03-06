SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

CPP = c++
FLAG = -Werror -Wall -Wextra

NAME = Animal

$(NAME): $(SRCS)
	$(CPP) $(FLAG) -o $(NAME) $(SRCS)

all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re