/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 02:21:42 by naykim            #+#    #+#             */
/*   Updated: 2021/07/29 02:21:44 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_collision(t_vars *v, int kc)
{
	t_xy	xy;

	xy.x = 0;
	xy.y = 0;
	if (kc == K_UP_W)
		xy.y = -1;
	else if (kc == K_DOWN_S)
		xy.y = 1;
	else if (kc == K_LEFT_A)
		xy.x = -1;
	else if (kc == K_RIGHT_D)
		xy.x = 1;
	else
		return (1);
	if (v->m.map[v->s.p.xy.y + xy.y][v->s.p.xy.x + xy.x] == 1)
		v->collision = 1;
	if (v->m.map[v->s.p.xy.y + xy.y][v->s.p.xy.x + xy.x] == 3)
		v->collision = 2;
	if (v->collision != 1)
		no_collision(v, &xy);
	return (0);
}

void	no_collision(t_vars *v, t_xy *xy)
{
	if (v->collision == 2)
	{
		if (v->score == v->m.c)
		{
			v->move++;
			finish_game(v);
		}
		else
		{
			printf("=====================WARNING====================\n");
			printf("         You should collect all %d balls\n", v->m.c);
			printf("If you can't, press ESC or RED CROSS on left top\n");
			printf("================================================\n");
		}
		return ;
	}
	v->m.map[v->s.p.xy.y][v->s.p.xy.x] = 0;
	my_put_image(v, v->s.p.xy.x, v->s.p.xy.y, &v->s.f);
	v->s.p.xy.x += xy->x;
	v->s.p.xy.y += xy->y;
	my_put_image(v, v->s.p.xy.x, v->s.p.xy.y, &v->s.f);
	my_put_image(v, v->s.p.xy.x, v->s.p.xy.y, &v->s.p);
	v->move++;
}
