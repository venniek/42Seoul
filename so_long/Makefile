# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/29 14:23:16 by naykim            #+#    #+#              #
#    Updated: 2021/07/29 14:23:20 by naykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

NAME = so_long
NAME_B = so_long_bonus

MLX = libmlx.a
MLX_DIR = ./mlx

INC = -I./includes

SRCS = 	srcs/get_next_line.c\
		srcs/get_next_line_utils.c\
		srcs/map_parsing.c\
		srcs/main.c\
		srcs/check.c\
		srcs/utils.c\
		srcs/event.c\
		srcs/draw_map.c\
		srcs/img.c

SRCS_B = srcs/get_next_line_bonus.c\
		srcs/get_next_line_utils_bonus.c\
		srcs/map_parsing_bonus.c\
		srcs/draw_map_bonus.c\
		srcs/main_bonus.c\
		srcs/error_bonus.c\
		srcs/util_1_bonus.c\
		srcs/util_2_bonus.c\
		srcs/mlx_bonus.c\
		srcs/mlx_img_bonus.c\
		srcs/collision_bonus.c\
		srcs/patrol_bonus.c\
		srcs/other_bonus.c

%.o: %.c
	$(CC) $(INC) -Imlx -c $< -o $@

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

$(NAME) : $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	cp $(MLX_DIR)/$(MLX) .
	$(CC) $(CFLAGS) $(OBJS) -L. -lmlx -framework OpenGL -framework AppKit -o $@

$(NAME_B) : $(OBJS_B)
	$(MAKE) -C $(MLX_DIR)
	cp $(MLX_DIR)/$(MLX) .
	$(CC) $(CFLAGS) $(OBJS_B) -L. -lmlx -framework OpenGL -framework AppKit -o $@

bonus: $(NAME_B)

all: $(NAME) $(NAME_B)

clean:
	$(RM) $(OBJS) $(OBJS_B)
	
fclean: clean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(NAME) $(MLX) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re bonus libmlx.a
