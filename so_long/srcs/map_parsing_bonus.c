/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:47:49 by naykim            #+#    #+#             */
/*   Updated: 2021/07/28 14:47:51 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	default_map(t_vars *v)
{
	v->move = 0;
	v->score = 0;
	v->mlx = 0;
	v->win = 0;
	v->collision = 0;
	v->patcnt = 0;
	v->m.map = 0;
	v->m.h = 0;
	v->m.w = 0;
	v->m.c = 0;
	v->m.p = 0;
	v->m.e = 0;
}

void	make_map(char *av[], t_vars *v)
{
	int	i;

	get_info(av, v);
	i = -1;
	v->m.map = (int **)malloc(sizeof(int *) * v->m.h);
	if (!v->m.map)
		ft_exit(v, 1);
	while (++i < v->m.h)
	{
		v->m.map[i] = (int *)malloc(sizeof(int) * v->m.w);
		if (!v->m.map[i])
			ft_exit(v, 1);
	}
	make_info(av, v);
}

void	get_info(char *av[], t_vars *v)
{
	char	*line;
	int		fd;
	int		size;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		map_error(v, 8);
	while (1)
	{
		size = get_next_line(fd, &line);
		v->m.h++;
		if (v->m.w == 0 && ft_strlen(line) == 0)
			map_error(v, 1);
		v->m.w = ft_max(v->m.w, ft_strlen(line));
		if (ft_strcmp(line, "", v) == 0)
			v->m.h--;
		free(line);
		line = 0;
		if (size == 0)
			break ;
	}
}

void	make_info(char *av[], t_vars *v)
{
	int		i;
	int		k;
	int		fd;
	int		size;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		map_error(v, 8);
	k = 0;
	while (1)
	{
		size = get_next_line(fd, &line);
		if (ft_strlen(line) > 0 && ft_strlen(line) != v->m.w)
			map_error(v, 1);
		i = -1;
		while (++i < ft_strlen(line))
			v->m.map[k][i] = char_to_i(line[i], v);
		free(line);
		line = 0;
		if (size == 0)
			break ;
		k++;
	}
}
