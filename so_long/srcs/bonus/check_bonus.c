#include "../../includes/so_long_bonus.h"

void	map_error(t_vars *v, int a)
{
	if (a == 1)
		ft_putstr_fd("not rectangular\n", 2);
	else if (a == 2)
		ft_putstr_fd("not surrounded by wall\n", 2);
	else if (a == 3)
		ft_putstr_fd("no escape door\n", 2);
	else if (a == 4)
		ft_putstr_fd("no player\n", 2);
	else if (a == 5)
		ft_putstr_fd("too many player\n", 2);
	else if (a == 6)
		ft_putstr_fd("no collectable item\n", 2);
	else if (a == 7)
		ft_putstr_fd("strange thing in map\n", 2);
	else if (a == 8)
		ft_putstr_fd("no such map\n", 2);
	ft_putstr_fd("Error\n", 2);
	ft_exit(v, 1);
}

void	check_map_error(t_vars *v)
{
	if (v->m.w == 0 || v->m.h == 0)
		map_error(v, 8);
	if (v->m.e == 0)
		map_error(v, 3);
	if (v->m.p == 0)
		map_error(v, 4);
	if (v->m.p > 1)
		map_error(v, 5);
	if (v->m.c == 0)
		map_error(v, 6);
	check_map_rec(v);
}

void	check_map_rec(t_vars *v)
{
	int	i;
	int	k;

	i = -1;
	while (++i < v->m.h)
	{
		k = -1;
		while (++k < v->m.w)
		{
			if (i == 0 || i == v->m.h - 1)
			{
				if (v->m.map[i][k] != 1)
					map_error(v, 2);
			}
			else if (k == 0 || k == v->m.w - 1)
			{
				if (v->m.map[i][k] != 1)
					map_error(v, 2);
			}
		}
	}
}

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
	if (v->m.map[v->s.p.xy.y + xy.y][v->s.p.xy.x + xy.x] == 1)
		v->collision = 1;
	if (v->m.map[v->s.p.xy.y + xy.y][v->s.p.xy.x + xy.x] == 3)
		v->collision = 2;
	if (v->collision != 1)
		no_collision(v, &xy);
	return (0);
}

void	no_collision(t_vars *v, t_xy *xy)
{
	if (v->collision == 2)
	{
		if (v->score == v->m.c)
		{
			v->move++;
			printf("move: %d\n", v->move);
			finish_game(v);
		}
		else
		{
			printf("You should collect all balls\n");
			printf("If you can't, press ESC or RED CROSS on left top\n\n");
		}
		return ;
	}
	v->m.map[v->s.p.xy.y][v->s.p.xy.x] = 0;
	my_put_image(v, v->s.p.xy.x, v->s.p.xy.y, &v->s.f);
	v->s.p.xy.x += xy->x;
	v->s.p.xy.y += xy->y;
	my_put_image(v, v->s.p.xy.x, v->s.p.xy.y, &v->s.f);
	my_put_image(v, v->s.p.xy.x, v->s.p.xy.y, &v->s.p);
	v->move++;
	print_move_on_map(v);
}

void print_move_on_map(t_vars *v)
{
	int i;

	i = -1;
	while (++i < ft_min(10, v->m.w))
		my_put_image(i, 0, v->m.h - 1, &v->s.w);
	my_string_put(v, 0, v->m.h, "move: ");
	my_string_put(v, 2, v->m.h, integer_to_string(v->move));
	my_string_put(v, 4, v->m.h, "score: ");
	my_string_put(v, 6, v->m.h, integer_to_string(v->score));
	
}
