SRCS = main.cpp Bureaucrat.cpp

CPP = c++
FLAG = -Werror -Wall -Wextra

NAME = Bureaucrat

$(NAME): $(SRCS)
	$(CPP) $(FLAG) -o $(NAME) $(SRCS)

all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re