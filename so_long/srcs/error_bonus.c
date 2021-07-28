/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:25:05 by naykim            #+#    #+#             */
/*   Updated: 2021/07/28 12:25:07 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	check_map_wall(v);
}

void	check_map_wall(t_vars *v)
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

int	is_ber(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = len;
	if (str[--i] != 'r')
		return (0);
	if (str[--i] != 'e')
		return (0);
	if (str[--i] != 'b')
		return (0);
	if (str[--i] != '.')
		return (0);
	return (1);
}
