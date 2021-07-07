# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/02 15:47:18 by naykim            #+#    #+#              #
#    Updated: 2021/04/13 05:05:20 by naykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rsc
RM = rm -f

NAME = libftprintf.a

SRCS = ft_printf.c parsing_all.c make_print_1.c make_print_2.c print_1.c print_2.c util_1.c util_2.c

OBJS = $(SRCS:.c=.o)


%.o: %.c
	$(CC) $(CFLAGS) -c $(SRCS)

$(NAME) : $(OBJS)
	$(AR) $@ $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
