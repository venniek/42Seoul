/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:23:43 by naykim            #+#    #+#             */
/*   Updated: 2021/07/28 12:23:49 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_keypress(int kc, t_vars *v)
{
	v->collision = 0;
	if (kc == K_ESC)
		ft_exit(v, 0);
	if (check_collision(v, kc) == 1)
		return (0);
	if (v->m.map[v->s.p.xy.y][v->s.p.xy.x] == 2)
		v->score++;
	if (v->collision != 2)
		v->m.map[v->s.p.xy.y][v->s.p.xy.x] = 4;
	return (0);
}

int	ft_click(t_vars *v)
{
	ft_exit(v, 0);
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
