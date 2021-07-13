#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_data{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
}	t_data;

typedef struct s_vars {
	void *mlx;
	void *win;
	void *img;
	int width;
	int height;
} t_vars;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int close(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{	
		exit(0);
	}
	return 0;
}

int main(void)
{
	t_vars vars;
	t_data img;


	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "start");
	vars.img = mlx_png_file_to_image(vars.mlx, "./imgs/udemy-icon.png", &vars.width, &vars.height);
	img.img = mlx_new_image(vars.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (int i = 240; i < 260; i++)
	{
		for (int k = 240; k < 260; k++)
			my_mlx_pixel_put(&img, i, k, 0x00FFFFFF);
	}
//	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);	
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
	return 0;
}
