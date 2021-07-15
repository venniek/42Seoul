#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_so_long.h"

typedef struct s_img{
	void *img;
	char *addr;
	int width;
	int height;
	int bpp;
	int line_length;
	int endian;
}	t_img;

typedef struct s_vars {
	void *mlx;
	void *win;
} t_vars;

void my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int ft_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{	
		exit(0);
	}
	return 0;
}

int main(int ac, char *av[])
{
	t_vars vars;
	t_img img;
	t_map map;

/*	if (ac < 2)
	{
		ft_putstr_fd("no maps\n", 2);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	default_map(&map);
	make_map(av, &map);
	check_map_error(&map);
*/	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "start");
	img.img = mlx_xpm_file_to_image(vars.mlx, "./imgs/wall_n.xpm", &(img.width), &(img.height));
	img.addr = mlx_get_data_addr(img.img, &(img.bpp), &(img.line_length), &(img.endian));
	int y = 0;
	while (y < img.height)
	{
		int x = 0;
		while (x < img.width)
		{
			if (x % 10 == 0)
				img.addr[img.width * y + x] = (char)0x00FF00;   // ?????
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
	mlx_loop(vars.mlx);
	return 0;
}
