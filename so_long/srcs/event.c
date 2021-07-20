#include "../includes/so_long.h"

int	check_collision(t_vars *v, int kc)
{
	t_xy	xy;

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

int	ft_keypress(int kc, t_vars *v)
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

int	ft_click(t_vars *v)
{
	ft_exit(v, 0);
	return 0;
}

void	ft_exit(t_vars *v, int i)
{
	int i;

	i = -1;
	mlx_destroy_window(v->mlx, v->win);
	if (v->m.map != 0)
	{
		while (++i < v->m.height)
		{
			free(v->m.map[i]);
			v->m.map[i] = 0;
		}
		free(v->m.map);
		v->m.map = 0;
	}
//	system("leaks so_long");
	exit(i);
}

void	finish_game(t_vars *v)
{
	printf("move: %d\n", v->move);
	printf("Your score is %d/%d(yours/total) in %d moves\n", v->score, v->m.collect, v->move);
//	system("leaks so_long");
	ft_exit(v, 0);
}