CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

NAME = so_long
NAME_B = so_long_bonus

MLX = libmlx.a
MLX_DIR = ./mlx

INC = -I./includes -I./mlx

SRCS = 	srcs/get_next_line.c\
		srcs/get_next_line_utils.c\
		srcs/map_parsing.c\
		srcs/main.c\
		srcs/check.c\
		srcs/utils.c\
		srcs/event.c\
		srcs/draw_map.c\
		srcs/img.c

SRCS_B = srcs/bonus/get_next_line_bonus.c\
		srcs/bonus/get_next_line_utils_bonus.c\
		srcs/bonus/map_parsing_bonus.c\
		srcs/bonus/main_bonus.c\
		srcs/bonus/check_bonus.c\
		srcs/bonus/utils_bonus.c\
		srcs/bonus/event_bonus.c\
		srcs/bonus/draw_map_bonus.c\
		srcs/bonus/img_bonus.c\
		srcs/bonus/util_map.c

%.o: %.c
	$(CC) -Imlx -c $< -o $@

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
	@$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(NAME) $(MLX) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re bonus libmlx.a
