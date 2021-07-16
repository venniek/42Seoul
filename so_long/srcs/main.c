#include "../ft_so_long.h"

void my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int ft_keypress(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{	
		exit(0);
	}
/*	if (keycode == K_UP_W)
	{

	}
*/
	return 0;
}

void print_map(t_map *map)
{
	for (int i = 0; i < map->height; i++)
	{
		for (int k = 0; k < map->width; k++)
			printf("%2d", map->map[i][k]);
		printf("\n");
	}
}

int main(int ac, char *av[])
{
	t_vars vars;
	t_img img;
	t_map map;
	t_sprite sprite;

	if (ac < 2)
	{
		ft_putstr_fd("no map\n", 2);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	default_map(&map);
	make_map(av, &map);
	check_map_error(&map);
	print_map(&map);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 800, "Bye Andy");  // 새 창 띄우기
	//wall
	sprite.wall.img = mlx_xpm_file_to_image(vars.mlx, "./imgs/cloud_wall.xpm", &(sprite.wall.width), &(sprite.wall.height));
	sprite.wall.addr = mlx_get_data_addr(sprite.wall.img, &(sprite.wall.bpp), &(sprite.wall.line_length), &(sprite.wall.endian));
	//floor
	sprite.floor.img = mlx_xpm_file_to_image(vars.mlx, "./imgs/floor_2.xpm", &(sprite.floor.width), &(sprite.floor.height));
	sprite.floor.addr = mlx_get_data_addr(sprite.floor.img, &(sprite.floor.bpp), &(sprite.floor.line_length), &(sprite.floor.endian));
	//escape
	sprite.escape.img = mlx_xpm_file_to_image(vars.mlx, "./imgs/escape_3.xpm", &(sprite.escape.width), &(sprite.escape.height));
	sprite.escape.addr = mlx_get_data_addr(sprite.escape.img, &(sprite.escape.bpp), &(sprite.escape.line_length), &(sprite.escape.endian));
	//collect
	sprite.collect.img = mlx_xpm_file_to_image(vars.mlx, "./imgs/collect.xpm", &(sprite.collect.width), &(sprite.collect.height));
	sprite.collect.addr = mlx_get_data_addr(sprite.collect.img, &(sprite.collect.bpp), &(sprite.collect.line_length), &(sprite.collect.endian));
	//player
	sprite.player.img = mlx_xpm_file_to_image(vars.mlx, "./imgs/player.xpm", &(sprite.player.width), &(sprite.player.height));
	sprite.player.addr = mlx_get_data_addr(sprite.player.img, &(sprite.player.bpp), &(sprite.player.line_length), &(sprite.player.endian));
	draw_map(&vars, &map, &sprite);;
	draw_sprite(&vars, &map, &sprite);
	mlx_hook(vars.win, 2, 1L<<0, ft_keypress, &vars);
	mlx_loop(vars.mlx);
	return 0;
}

void draw_map(t_vars *vars, t_map *map, t_sprite *sprite)
{
	for (int i = 0; i < map->height; i++)
	{
		for (int k = 0; k < map->width; k++)
		{
			if (map->map[i][k] == 1)
				mlx_put_image_to_window(vars->mlx, vars->win, sprite->wall.img, k * sprite->wall.width, i * sprite->wall.height);
			else
				mlx_put_image_to_window(vars->mlx, vars->win, sprite->floor.img, k * sprite->wall.width, i * sprite->wall.height);
		}
	}
}

void draw_sprite(t_vars *vars, t_map *map, t_sprite *sprite)
{
	for (int i = 0; i < map->height; i++)
	{
		for (int k = 0; k < map->width; k++)
		{
			if (map->map[i][k] == 2)
				mlx_put_image_to_window(vars->mlx, vars->win, sprite->collect.img, k * sprite->collect.width, i * sprite->collect.height);
			if (map->map[i][k] == 3)
				mlx_put_image_to_window(vars->mlx, vars->win, sprite->escape.img, k * sprite->escape.width, i * sprite->escape.height);
			if (map->map[i][k] == 4)
				mlx_put_image_to_window(vars->mlx, vars->win, sprite->player.img, k * sprite->player.width, i * sprite->player.height);
		}
	}
}