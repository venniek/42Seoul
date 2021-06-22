# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 15:57:03 by naykim            #+#    #+#              #
#    Updated: 2021/06/22 18:23:51 by naykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
RM = rm -f

NAME = push_swap
SRCS = srcs/main.c\
		srcs/push_swap.c\
		srcs/push_swap_check.c\
		srcs/push_swap_under5.c\
		srcs/push_back_under3.c\
		srcs/orders.c\
		srcs/util_1.c\
		srcs/util_2.c\
		srcs/util_str.c
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
