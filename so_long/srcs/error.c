#include "../includes/so_long.h"

void	map_error(t_vars *v, int a)  ///빈줄 체크할건지???
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
	else if(a == 8)
		ft_putstr_fd("no such map\n", 2);
	ft_putstr_fd("Error\n", 2);
	ft_exit(v, 1);
}

void	check_map_error(t_vars *v)
{
	if (v->m.escape == 0)
		map_error(v, 3);
	if (v->m.player == 0)
		map_error(v, 4);
	if (v->m.player > 1)
		map_error(v, 5);
	if (v->m.collect == 0)
		map_error(v, 6);
	check_map_rec(v);
}

void	check_map_rec(t_vars *v)
{
	int	h;
	int	w;

	h = -1;
	while (++h < v->m.height)
	{
		w = -1;
		while (++w < v->m.width)
		{
			if (h == 0 || h == v->m.height - 1)
			{
				if (v->m.map[h][w] != 1)
					map_error(v, 2);
			}
			else
			{
				if (w == 0 || w == v->m.width - 1)
				{
					if (v->m.map[h][w] != 1)
						map_error(v, 2);
				}
			}
		}
	}
}