#include "../ft_so_long.h"
#include <string.h>

void default_map(t_vars *v)
{
	v->move = 0;
	v->mlx = 0;
	v->win = 0;
	v->collision = 0;
	v->m.map = 0;
	v->m.height = 0;
	v->m.width = 0;
	v->m.collect = 0;
	v->m.player = 0;
	v->m.escape = 0;
}

int char_to_i(char a, t_vars *v)   //0-empty 1-wall 2-collect 3-exit 4-player
{
	if (a == '0')
		return (0);
	if (a == '1')
		return (1);
	if (a == 'C')
	{
		v->m.collect++;
		return (2);
	}
	if (a == 'E')
	{
		v->m.escape++;
		return (3);
	}
	if (a == 'P')
	{
		v->m.player++;
		return (4);
	}
	map_error(7);
	return (-1);
}

void make_map(char *av[], t_vars *v)
{
	int fd;
	char *line;
	int size;
	int k;

	if ((fd = open(av[1], O_RDONLY)) < 0)
		map_error(8);
	while (get_next_line(fd, &line) > 0)
	{
		v->m.height++;
		v->m.width = ft_max(v->m.width, strlen(line));
	}
	if (strcmp(line, "") != 0)
		v->m.height++;
	v->m.map = (int **)malloc(sizeof(int *) * v->m.height);
	for (int i = 0; i < v->m.height; i++)
		v->m.map[i] = (int *)malloc(sizeof(int) * v->m.width);
	fd = open(av[1], O_RDONLY);
	k = 0;
	while ((size = get_next_line(fd, &line)) >= 0)
	{
		if (strlen(line) > 0 && strlen(line) < v->m.width)
			map_error(1);
		for(int i = 0; i < v->m.width && line[i]; i++)
			v->m.map[k][i] = char_to_i(line[i], v);  //0-empty 1-wall 2-collect 3-exit 4-player
		if (size == 0)
			break;
		k++;
	}
}