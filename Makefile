# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 15:57:03 by naykim            #+#    #+#              #
#    Updated: 2021/06/29 17:06:28 by naykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

NAME_P = push_swap
NAME_C = checker

SRCS_P = srcs/main.c\
		srcs/orders.c\
		srcs/push_swap.c\
		srcs/push_swap_main.c\
		srcs/push_swap_check.c\
		srcs/push_swap_under5.c\
		srcs/push_back_under3.c\
		srcs/util_free.c\
		srcs/util_main.c\
		srcs/util_order.c\
		srcs/util_other.c\
		srcs/util_str.c
SRCS_C = srcs/main.c\
		srcs/checker_gnl.c\
		srcs/checker_main.c\
		srcs/orders.c\
		srcs/util_free.c\
		srcs/util_main.c\
		srcs/util_order.c\
		srcs/util_other.c\
		srcs/util_str.c

OBJS_P = $(SRCS_P:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)

$(NAME_P) : $(OBJS_P)
	$(CC) $(CFLAGS) -o $@ $(OBJS_P)
$(NAME_C) : $(OBJS_C)
	$(CC) $(CFLAGS) -o $@ $(OBJS_C)

all: $(NAME_C) $(NAME_P)

clean:
	$(RM) $(OBJS_P) $(OBJS_C)

fclean: clean
	$(RM) $(NAME_P) $(NAME_C)

re: fclean all

.PHONY: all clean fclean re
