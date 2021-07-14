#include "ft_so_long.h"
#include <string.h>

int char_to_i(char a)   //0-empty 1-wall 2-collect 3-exit 4-player
{
	if (a == '0')
		return (0);
	if (a == '1')
		return (1);
	if (a == 'C')
		return (2);
	if (a == 'E')
		return (3);
	if (a == 'P')
		return (4);
	return (-1);
}

void make_map(char *av[], t_map *map)
{
	int fd = open(av[1], O_RDONLY);
	char *line;
	int size;

	map->height = 0;
	while ((size = get_next_line(fd, &line)) > 0)
	{
		map->height++;
		map->width = strlen(line);
	}
	printf("height: %d\n", map->height);
	if (line == 0 || strcmp(line, "\0") != 0)
		map->height++;
	printf("last line strlen: %d\n", map->width);
	map->map = (int **)malloc(sizeof(int *) * map->height);
	for (int i = 0; i < map->height; i++)
		map->map[i] = (int *)malloc(sizeof(int) * map->width);
	fd = open(av[1], O_RDONLY);
	int k = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (strlen(line) != map->width)
		{
			printf("invalid map\n");
			exit(1);
		}
	
		for(int i = 0; i < map->width; i++)
			map->map[k][i] = char_to_i(line[i]);  //0-empty 1-wall 2-collect 3-exit 4-player
		k++;
	}
	for (int i = 0; i < map->width; i++)
		map->map[k][i] = char_to_i(line[i]);
	printf("map->width:  %2d\n", map->width);
	printf("map->height: %2d\n", map->height);
}

int main(int ac, char *av[])
{
	t_map map;
	make_map(av, &map);
	for (int i = 0; i < map.height; i++)
	{
		for (int k = 0; k < map.width; k++)
			printf("%2d", map.map[i][k]);
		printf("\n");
	}
	return 0;
}