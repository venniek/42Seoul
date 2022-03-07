SRCS = main.cpp AMateria.cpp ICharacter.cpp IMateriaSource.cpp

CPP = c++
FLAG = -Werror -Wall -Wextra

NAME = Materia

$(NAME): $(SRCS)
	$(CPP) $(FLAG) -o $(NAME) $(SRCS)

all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re