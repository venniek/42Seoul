#include "ft_so_long.h"

void map_error(int a)  ///빈줄 체크할건지???
{
	if (a == 1)
		ft_putstr_fd("not rectangular\n", 2);
	else if (a == 2)
		ft_putstr_fd("not surrounded by wall\n", 2);
	else if (a == 3)
		ft_putstr_fd("no escape door\n", 2);
	else if (a == 4)
		ft_putstr_fd("no player location\n", 2);
	else if (a == 5)
		ft_putstr_fd("too many player location\n", 2);
	else if (a == 6)
		ft_putstr_fd("no collectable item\n", 2);
	else if (a == 7)
		ft_putstr_fd("strange thing in map\n", 2);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void check_map_error(t_map *map)
{
	if (map->escape == 0)
		map_error(3);
	if (map->player == 0)
		map_error(4);
	if (map->player > 1)
		map_error(5);
	if (map->collect == 0)
		map_error(6);
	for (int i = 0; i < map->height; i++)
	{
		for (int k = 0; k < map->width; k++)
		{
			if (i == 0 || i == map->height - 1)
			{
				if (map->map[i][k] != 1)
					map_error(2);
			}
			else
			{
				if (k == 0 || k == map->width - 1)
				{
					if (map->map[i][k] != 1)
						map_error(2);
				}
				else
				continue;
			}
		}
	}
}