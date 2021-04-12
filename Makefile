# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/02 15:47:18 by naykim            #+#    #+#              #
#    Updated: 2021/04/06 14:45:02 by naykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

NAME = libftprintf.a

SRCS = ft_printf.c libft_util.c parsing_all.c make_print_1.c print_1.c

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
