#include "../ft_so_long.h"

void my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int check_collision(t_vars *v, int kc)
{
	if (kc == K_UP_W)
	{
		if (v->m.map[v->s.player.y - 1][v->s.player.x] == 1)
			v->collision = 1;
	}
	else if (kc == K_DOWN_S)
	{
		if (v->m.map[v->s.player.y + 1][v->s.player.x] == 1)
			v->collision = 1;
	}
	else if (kc == K_LEFT_A)
	{
		if (v->m.map[v->s.player.y][v->s.player.x - 1] == 1)
			v->collision = 1;
	}
	else if (kc == K_RIGHT_D)
	{
		if (v->m.map[v->s.player.y][v->s.player.x + 1] == 1)
			v->collision = 1;
	}
	if (v->collision == 0)
	{
		v->move++;
		return (0);
	}
	else
		return (1);
}

void finish_game(t_vars *v)
{
	printf("move: %d\n", v->move);
//	printf("You have finished game in %d moves\n", v->move);
	printf("Your score is %d/%d(yours/total) in %d moves\n", v->score, v->m.collect, v->move);
	ft_exit(v, 0);
}

int ft_keypress(int kc, t_vars *v)
{
	v->collision = 0;
	if (kc == K_ESC)
		ft_exit(v, 0);
	else if (kc == K_UP_W && check_collision(v, kc) == 0)
		v->m.map[v->s.player.y--][v->s.player.x] = 0;
	else if (kc == K_DOWN_S && check_collision(v, kc) == 0)
		v->m.map[v->s.player.y++][v->s.player.x] = 0;
	else if (kc == K_LEFT_A && check_collision(v, kc) == 0)
		v->m.map[v->s.player.y][v->s.player.x--] = 0;
	else if (kc == K_RIGHT_D && check_collision(v, kc) == 0)
		v->m.map[v->s.player.y][v->s.player.x++] = 0;
	if (v->m.map[v->s.player.y][v->s.player.x] == 3)
		finish_game(v);
	else if (v->m.map[v->s.player.y][v->s.player.x] == 2)
		v->score++;
	v->m.map[v->s.player.y][v->s.player.x] = 4;
	repeat(v);
	return 0;
}

void print_map(t_vars *v)
{
	for (int i = 0; i < v->m.height; i++)
	{
		for (int k = 0; k < v->m.width; k++)
			printf("%2d", v->m.map[i][k]);
		printf("\n");
	}
}

int main(int ac, char *av[])
{
	t_vars v;

	if (ac < 2)
	{
		ft_putstr_fd("no map\n", 2);
		ft_putstr_fd("Error\n", 2);
		ft_exit(&v, 1);
	}
	memset(&v, 0, sizeof(t_vars));
	default_map(&v);
	make_map(av, &v);
//	print_map(&v);
//	printf("v->m.player: %d\n", v.m.player);
	check_map_error(&v);
//	printf("v->move: %d\n", v.move);
//	printf("v->score: %d\n", v.score);
//	printf("v->collision: %d\n", v.collision);
//	print_map(&v);
	v.mlx = mlx_init();
	v.win = mlx_new_window(v.mlx, v.m.width * 32, v.m.height * 32, "Bye Andy");
	//wall
	v.s.wall.img = mlx_xpm_file_to_image(v.mlx, "./imgs/cloud_wall.xpm", &(v.s.wall.width), &(v.s.wall.height));
	v.s.wall.addr = mlx_get_data_addr(v.s.wall.img, &(v.s.wall.bpp), &(v.s.wall.line_length), &(v.s.wall.endian));
	//floor
	v.s.floor.img = mlx_xpm_file_to_image(v.mlx, "./imgs/floor_2.xpm", &(v.s.floor.width), &(v.s.floor.height));
	v.s.floor.addr = mlx_get_data_addr(v.s.floor.img, &(v.s.floor.bpp), &(v.s.floor.line_length), &(v.s.floor.endian));
	//escape
	v.s.escape.img = mlx_xpm_file_to_image(v.mlx, "./imgs/escape_3.xpm", &(v.s.escape.width), &(v.s.escape.height));
	v.s.escape.addr = mlx_get_data_addr(v.s.escape.img, &(v.s.escape.bpp), &(v.s.escape.line_length), &(v.s.escape.endian));
	//collect
	v.s.collect.img = mlx_xpm_file_to_image(v.mlx, "./imgs/collect.xpm", &(v.s.collect.width), &(v.s.collect.height));
	v.s.collect.addr = mlx_get_data_addr(v.s.collect.img, &(v.s.collect.bpp), &(v.s.collect.line_length), &(v.s.collect.endian));
	//player
	v.s.player.img = mlx_xpm_file_to_image(v.mlx, "./imgs/player.xpm", &(v.s.player.width), &(v.s.player.height));
	v.s.player.addr = mlx_get_data_addr(v.s.player.img, &(v.s.player.bpp), &(v.s.player.line_length), &(v.s.player.endian));
	map_repeat(&v);
	mlx_hook(v.win, 2, 1L<<0, ft_keypress, &v);
	mlx_loop(v.mlx);
	
	return 0;
}

void map_repeat(t_vars *v)
{
//	printf("v->collision: %d\n", v->collision);
	if (v->collision == 0)
		printf("move: %d\n", v->move);
//	printf("before draw_map\n");
	draw_map(v);
//	printf("after draw_map\n");
	draw_sprite(v);
//	printf("after draw_sprite\n");
}

void draw_map(t_vars *v)
{
//	printf("in draw_map\n");
	for (int i = 0; i < v->m.height; i++)
	{
		for (int k = 0; k < v->m.width; k++)
		{
			if (v->m.map[i][k] == 1)
				mlx_put_image_to_window(v->mlx, v->win, v->s.wall.img, k * v->s.wall.width, i * v->s.wall.height);
			else
				mlx_put_image_to_window(v->mlx, v->win, v->s.floor.img, k * v->s.wall.width, i * v->s.wall.height);
		//	printf("after map[%d]\n", i);
		}
	}
}

void draw_sprite(t_vars *v)
{
	for (int i = 0; i < v->m.height; i++)
	{
		for (int k = 0; k < v->m.width; k++)
		{
			if (v->m.map[i][k] == 2)
				mlx_put_image_to_window(v->mlx, v->win, v->s.collect.img, k * v->s.collect.width, i * v->s.collect.height);
			if (v->m.map[i][k] == 3)
				mlx_put_image_to_window(v->mlx, v->win, v->s.escape.img, k * v->s.escape.width, i * v->s.escape.height);
			if (v->m.map[i][k] == 4)
			{
				v->s.player.x = k;
				v->s.player.y = i;
				mlx_put_image_to_window(v->mlx, v->win, v->s.player.img, k * v->s.player.width, i * v->s.player.height);
			}
		}
	}
}