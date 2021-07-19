#include "../ft_so_long.h"

void ft_exit(t_vars *v, int i)
{
	mlx_destroy_window(v->mlx, v->win);
	for (int i = 0; i < v->m.height; i++)
	{
		free(v->m.map[i]);
		v->m.map[i] = 0;
	}
	free(v->m.map);
	v->m.map = 0;
//	system("leaks so_long");
	exit(i);
}

int check_collision(t_vars *v, int kc)
{
	t_xy xy;

	xy.x = 0;
	xy.y = 0;
	if (kc == K_UP_W)
		xy.y = -1;
	else if (kc == K_DOWN_S)
		xy.y = 1;
	else if (kc == K_LEFT_A)
		xy.x = -1;
	else if (kc == K_RIGHT_D)
		xy.x = 1;
	else
		return (1);
	if (v->m.map[v->s.player.y + xy.y][v->s.player.x + xy.x] == 1)
			v->collision = 1;
	if (v->collision == 0)
	{
		v->m.map[v->s.player.y][v->s.player.x] = 0;
		v->s.player.x += xy.x;
		v->s.player.y += xy.y;
		v->move++;
	}
	return (0);
}

void finish_game(t_vars *v)
{
	printf("move: %d\n", v->move);
	printf("Your score is %d/%d(yours/total) in %d moves\n", v->score, v->m.collect, v->move);
//	system("leaks so_long");
	ft_exit(v, 0);
}

int ft_keypress(int kc, t_vars *v)
{
	v->collision = 0;
	if (kc == K_ESC)
		ft_exit(v, 0);
	if (check_collision(v, kc) == 1)
		return (0);
	if (v->m.map[v->s.player.y][v->s.player.x] == 3)
		finish_game(v);
	else if (v->m.map[v->s.player.y][v->s.player.x] == 2)
		v->score++;
	v->m.map[v->s.player.y][v->s.player.x] = 4;
	map_repeat(v);
	return 0;
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
	check_map_error(&v);
	make_all(&v);
	map_repeat(&v);
	mlx_hook(v.win, 2, 1L<<0, ft_keypress, &v);
	mlx_hook(v.win, 17, 0, ft_click, &v);
	mlx_loop(v.mlx);
	
	return 0;
}

int ft_click(t_vars *v)
{
	ft_exit(v, 0);
	return 0;
}

void map_repeat(t_vars *v)
{
	char *move;

	if (v->collision == 0)
		printf("move: %d\n", v->move);
	draw_map(v);
	draw_sprite(v);
	move = print_integer(v);
	mlx_string_put(v->mlx, v->win, 0, (v->m.height - 0.5) * v->s.wall.height, 0x000000,"move: ");
	mlx_string_put(v->mlx, v->win, v->s.wall.width * 2, (v->m.height - 0.5) * v->s.wall.height, 0x000000, move);
	free(move);
	move = 0;
	// score??
}

char *print_integer(t_vars *v)
{
	char *move;
	int mcopy;
	int len;

	len = 0;
	mcopy = v->move;
	while (mcopy > 0)
	{
		len++;
		mcopy /= 10;
	}
	mcopy = v->move;
	move = (char *)malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++)
	{
		move[i] = mcopy % 10 + '0';
		mcopy /= 10;
	}
	move[len] = '\0';
	for (int i = 0; i < len / 2; i++)
	{
		char tmp;
		tmp = move[i];
		move[i] = move[len - i - 1];
		move[len - i - 1] = tmp;
	}
	return (move);
}

void draw_map(t_vars *v)
{
	for (int i = 0; i < v->m.height; i++)
	{
		for (int k = 0; k < v->m.width; k++)
		{
			if (v->m.map[i][k] == 1)
				mlx_put_image_to_window(v->mlx, v->win, v->s.wall.img, k * v->s.wall.width, i * v->s.wall.height);
			else
				mlx_put_image_to_window(v->mlx, v->win, v->s.floor.img, k * v->s.wall.width, i * v->s.wall.height);
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