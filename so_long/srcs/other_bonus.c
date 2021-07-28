/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 02:21:55 by naykim            #+#    #+#             */
/*   Updated: 2021/07/29 02:21:57 by naykim           ###   ########.fr       */
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
	if (v->mlx != 0)
		mlx_destroy_window(v->mlx, v->win);
	if (v->m.map != 0)
	{
		while (++k < v->m.h)
		{
			free(v->m.map[k]);
			v->m.map[i] = 0;
		}
		free(v->m.map);
		v->m.map = 0;
	}
	system("leaks so_long_bonus");
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
