SRCS = all_test.cpp

CPP = c++
FLAG = -Werror -Wall -Wextra -std=c++98

NAME_FT = ft_containers
NAME_STD = std_containers

$(NAME_FT): $(SRCS)
	$(CPP) $(FLAG) -DUSING_FT -o $(NAME_FT) $(SRCS)
$(NAME_STD): $(SRCS)
	$(CPP) $(FLAG) -o $(NAME_STD) $(SRCS)

all: $(NAME_FT) $(NAME_STD)
	./$(NAME_FT) > ft.txt
	./$(NAME_STD) > std.txt
	diff ft.txt std.txt > diff.txt

clean:
	rm -f $(NAME_FT) $(NAME_STD) *.txt

re: clean all

.PHONY: all clean re