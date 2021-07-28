/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 02:22:06 by naykim            #+#    #+#             */
/*   Updated: 2021/07/29 02:22:07 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_keypress(int kc, t_vars *v)
{
	v->collision = 0;
	if (kc == K_ESC)
		ft_exit(v, 0);
	if (check_collision(v, kc) == 1)
		return (0);
	if (v->m.map[v->s.p.xy.y][v->s.p.xy.x] == 2)
		v->score++;
	print_move_on_map(v);
	if (v->collision != 2)
		v->m.map[v->s.p.xy.y][v->s.p.xy.x] = 4;
	return (0);
}

int	ft_click(t_vars *v)
{
	ft_exit(v, 0);
	return (0);
}

void	my_string_put(t_vars *v, int w, int h, char *str)
{
	int	wid;
	int	hei;

	wid = v->s.w.w * w + v->s.w.w / 2;
	hei = v->s.w.h * h - v->s.w.h / 2;
	mlx_string_put(v->mlx, v->win, wid, hei, 0x000000, str);
}

char	*integer_to_string(int n, t_vars *v)
{
	char	*move;
	int		ncopy;
	int		len;

	len = 0;
	ncopy = n;
	while (ncopy > 0)
	{
		len++;
		ncopy /= 10;
	}
	ncopy = n;
	move = (char *)malloc(sizeof(char) * (len + 1));
	if (move == NULL)
		ft_exit(v, 1);
	make_move(len, &move, ncopy);
	return (move);
}

void	print_move_on_map(t_vars *v)
{
	int		i;
	char	*str;

	i = -1;
	while (++i < ft_min(10, v->m.w))
		my_put_image(v, i, v->m.h - 1, &v->s.w);
	str = integer_to_string(v->move, v);
	my_string_put(v, 0, v->m.h, "move: ");
	my_string_put(v, 2, v->m.h, str);
	free(str);
	str = integer_to_string(v->score, v);
	my_string_put(v, 4, v->m.h, "score: ");
	my_string_put(v, 6, v->m.h, str);
	free(str);
	str = 0;
}
