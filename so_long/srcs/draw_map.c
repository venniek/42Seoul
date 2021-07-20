#include "../includes/so_long.h"


void	map_repeat(t_vars *v)
{
//	char *move;

	if (v->collision == 0)
		printf("move: %d\n", v->move);
	draw_map(v);
	draw_sprite(v);
//	move = print_integer(v);
//	mlx_string_put(v->mlx, v->win, 0, (v->m.height - 0.5) * v->s.wall.height, 0x000000,"move: ");
//	mlx_string_put(v->mlx, v->win, v->s.wall.width * 2, (v->m.height - 0.5) * v->s.wall.height, 0x000000, move);
//	free(move);
//	move = 0;
	// score??
}

void	draw_map(t_vars *v)
{
	int h;
	int w;

	h = -1;
	while (++h < v->m.height)
	{
		w = -1;
		while (++w < v->m.width)
		{
			mlx_put_image_to_window(v->mlx, v->win, v->s.floor.img, w * v->s.floor.width, h * v->s.floor.height);
			if (v->m.map[h][w] == 1)
			{
				if (h == 0 || h == v->m.height - 1 || w == 0 || w == v->m.width - 1)
					mlx_put_image_to_window(v->mlx, v->win, v->s.wall.img, w * v->s.wall.width, h * v->s.wall.height);
				else
					mlx_put_image_to_window(v->mlx, v->win, v->s.column.img, w * v->s.column.width, h * v->s.column.height);
			}
		}
	}
}

void	draw_sprite(t_vars *v)
{
	int h;
	int w;

	h = -1;
	while (++h < v->m.height)
	{
		w = -1;
		while (++w < v->m.width)
		{
			if (v->m.map[h][w] == 2)
		//	{
		//		if (v->move % 2 == 0)
					mlx_put_image_to_window(v->mlx, v->win, v->s.collect1.img, w * v->s.collect1.width, h * v->s.collect1.height);
		//		else
		//			mlx_put_image_to_window(v->mlx, v->win, v->s.collect2.img, w * v->s.collect2.width, h * v->s.collect2.height);
		//	}
			if (v->m.map[h][w] == 3)
				mlx_put_image_to_window(v->mlx, v->win, v->s.escape.img, w * v->s.escape.width, h * v->s.escape.height);
			if (v->m.map[h][w] == 4)
			{
				v->s.player.x = w;
				v->s.player.y = h;
				mlx_put_image_to_window(v->mlx, v->win, v->s.player.img, w * v->s.player.width, h * v->s.player.height);
			}
		}
	}
}

