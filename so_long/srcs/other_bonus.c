/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:57:23 by naykim            #+#    #+#             */
/*   Updated: 2021/07/29 15:57:26 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_animation(t_vars *v)
{
	int		h;
	int		w;
	int		i;

	i = -1;
	while (++i < v->patcnt)
		is_attack(v, i);
	h = -1;
	while (++h < v->m.h)
	{
		w = -1;
		while (++w < v->m.w)
		{
			if (v->m.map[h][w] < 2)
				continue ;
			redraw_map(v, w, h, time(NULL) - v->start);
		}
	}
	if (v->now != time(NULL))
	{
		moving_patrol(v);
		v->now++;
	}
	return (0);
}

void	ft_exit(t_vars *v, int i)
{
	int	k;

	k = -1;
	if (v->mlx)
		mlx_destroy_window(v->mlx, v->win);
	if (v->m.map)
	{
		while (++k < v->m.h)
		{
			if (v->m.map[k])
			{
				free(v->m.map[k]);
				v->m.map[k] = 0;
			}
		}
		if (v->m.map)
		{
			free(v->m.map);
			v->m.map = 0;
		}
	}
	exit(i);
}

void	finish_game(t_vars *v)
{
	printf("****************YOU WIN*****************\n");
	printf("*                                      *\n");
	printf("* You collected all balls in %3d moves *\n", v->move);
	printf("*                                      *\n");
	printf("****************************************\n");
	ft_exit(v, 0);
}
