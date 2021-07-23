CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

NAME = so_long

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

%.o: %.c
	$(CC) -Imlx -c $< -o $@

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	cp $(MLX_DIR)/$(MLX) .
	$(CC) $(CFLAGS) -g3 -fsanitize=address $(OBJS) -L. -lmlx -framework OpenGL -framework AppKit -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)
	
fclean: clean
	@$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(NAME) $(MLX)

re: fclean all

.PHONY: all clean fclean re libmlx.dylib
