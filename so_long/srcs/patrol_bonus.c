/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 02:57:40 by naykim            #+#    #+#             */
/*   Updated: 2021/07/29 02:57:42 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	moving_patrol(t_vars *v)
{
	int	i;

	i = -1;
	while (++i < v->patcnt)
	{
		if (patrol_move(v, i, 1, 0) == 1)
			continue ;
		if (patrol_move(v, i, 0, 1) == 1)
			continue ;
		if (patrol_move(v, i, -1, 0) == 1)
			continue ;
		if (patrol_move(v, i, 0, -1) == 1)
			continue ;
	}
	return (0);
}

int	is_pat(t_vars *v, int w, int h)
{
	if ((h + w) % 4 == 0 && h % 2 == 0 && v->patcnt < 5)
		return (1);
	return (0);
}

void	is_attack(t_vars *v, int i)
{
	int	patx;
	int	paty;

	patx = v->pat[i].xy.x;
	paty = v->pat[i].xy.y;
	if (paty == v->s.p.xy.y && patx == v->s.p.xy.x)
	{
		printf("------------YOU LOSE------------\n");
		printf("             !!NO!!              \n");
		printf("!!Lotso the bad bear caught you!!\n");
		printf("---------------------------------\n");
		ft_exit(v, 0);
	}
}

int	patrol_move(t_vars *v, int i, int x, int y)
{
	int	tmp;

	tmp = v->m.map[v->pat[i].xy.y + y][v->pat[i].xy.x + x];
	if (tmp == 0 || tmp == 4)
	{
		v->m.map[v->pat[i].xy.y][v->pat[i].xy.x] = 0;
		my_put_image(v, v->pat[i].xy.x, v->pat[i].xy.y, &v->s.f);
		v->pat[i].xy.x += x;
		v->pat[i].xy.y += y;
		v->m.map[v->pat[i].xy.y][v->pat[i].xy.x] = 5;
		my_put_image(v, v->pat[i].xy.x, v->pat[i].xy.y, &v->pat[i]);
		return (1);
	}
	else
		return (0);
}
