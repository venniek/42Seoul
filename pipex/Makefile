# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 17:02:01 by naykim            #+#    #+#              #
#    Updated: 2021/10/04 17:02:03 by naykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Werror -Wextra -Wall
RM = rm -f

LIBFT = libft.a
LIBFT_DIR = libft

NAME = pipex

INC = -I.

SRCS = pipex.c\
		preparation.c\
		processes.c\
		check.c\
		utils.c

%.o: %.c
	$(CC) -I. -I$(LIBFT_DIR) -c $< -o $@

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) .
	$(CC) $(CFLAGS) $(OBJS) -L. -lft -o $@

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re $(LIBFT)
