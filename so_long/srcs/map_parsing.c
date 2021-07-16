#include "../ft_so_long.h"
#include <string.h>

void default_map(t_map *map)
{
	map->map = 0;
	map->height = 0;
	map->width = 0;
	map->collect = 0;
	map->player = 0;
	map->escape = 0;
}

int char_to_i(char a, t_map *map)   //0-empty 1-wall 2-collect 3-exit 4-player
{
	if (a == '0')
		return (0);
	if (a == '1')
		return (1);
	if (a == 'C')
	{
		map->collect++;
		return (2);
	}
	if (a == 'E')
	{
		map->escape++;
		return (3);
	}
	if (a == 'P')
	{
		map->player++;
		return (4);
	}
	map_error(7);
	return (-1);
}

void make_map(char *av[], t_map *map)
{
	int fd;
	char *line;
	int size;
	int k;

	if ((fd = open(av[1], O_RDONLY)) < 0)
		map_error(8);
	while (get_next_line(fd, &line) > 0)
	{
		map->height++;
		map->width = ft_max(map->width, strlen(line));
	}
	if (strcmp(line, "") != 0)
		map->height++;
	map->map = (int **)malloc(sizeof(int *) * map->height);
	for (int i = 0; i < map->height; i++)
		map->map[i] = (int *)malloc(sizeof(int) * map->width);
	fd = open(av[1], O_RDONLY);
	k = 0;
	while ((size = get_next_line(fd, &line)) >= 0)
	{
		if (strlen(line) > 0 && strlen(line) < map->width)
			map_error(1);
		for(int i = 0; i < map->width && line[i]; i++)
			map->map[k][i] = char_to_i(line[i], map);  //0-empty 1-wall 2-collect 3-exit 4-player
		if (size == 0)
			break;
		k++;
	}
}