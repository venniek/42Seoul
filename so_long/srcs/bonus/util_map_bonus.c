/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:48:05 by naykim            #+#    #+#             */
/*   Updated: 2021/07/28 14:48:06 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	ft_animation(t_vars *v)
{
	int		h;
	int		w;
	int		i;
	time_t	cur;

	i = -1;
	while (++i < v->patcnt)
	{
		if (v->pat[i].img.xy.y == v->s.p.xy.y && v->pat[i].img.xy.x == v->s.p.xy.x)
		{
			printf("NO!!\n");
			ft_exit(v, 0);
		}
	}
	cur = time(NULL) - v->start;
	h = -1;
	while (++h < v->m.h)
	{
		w = -1;
		while (++w < v->m.w)
		{
			if (v->m.map[h][w] < 2)
				continue ;
			redraw_map(v, w, h, cur);
		}
	}
	if (v->now != time(NULL))
	{
		moving_patrol(v);
		v->now++;
	}
	return (0);
}

int	moving_patrol(t_vars *v)
{
	int	tmp;
	int	i;

	i = -1;
	while (++i < v->patcnt)
	{
		tmp = v->m.map[v->pat[i].img.xy.y + 1][v->pat[i].img.xy.x];
		if (tmp == 0 || tmp == 4)
		{
			v->m.map[v->pat[i].img.xy.y][v->pat[i].img.xy.x] = 0;
			my_put_image(v, v->pat[i].img.xy.x, v->pat[i].img.xy.y, &v->s.f);
			v->pat[i].img.xy.y += 1;
			v->m.map[v->pat[i].img.xy.y][v->pat[i].img.xy.x] = 5;
			my_put_image(v, v->pat[i].img.xy.x, v->pat[i].img.xy.y, &v->pat[i].img);
			continue ;
		}
		tmp = v->m.map[v->pat[i].img.xy.y][v->pat[i].img.xy.x + 1];
		if (tmp == 0 || tmp == 4)
		{
			v->m.map[v->pat[i].img.xy.y][v->pat[i].img.xy.x] = 0;
			my_put_image(v, v->pat[i].img.xy.x, v->pat[i].img.xy.y, &v->s.f);
			v->pat[i].img.xy.x += 1;
			v->m.map[v->pat[i].img.xy.y][v->pat[i].img.xy.x] = 5;
			my_put_image(v, v->pat[i].img.xy.x, v->pat[i].img.xy.y, &v->pat[i].img);
			continue ;
		}
		tmp = v->m.map[v->pat[i].img.xy.y - 1][v->pat[i].img.xy.x];
		if (tmp == 0 || tmp == 4)
		{
			v->m.map[v->pat[i].img.xy.y][v->pat[i].img.xy.x] = 0;
			my_put_image(v, v->pat[i].img.xy.x, v->pat[i].img.xy.y, &v->s.f);
			v->pat[i].img.xy.y -= 1;
			v->m.map[v->pat[i].img.xy.y][v->pat[i].img.xy.x] = 5;
			my_put_image(v, v->pat[i].img.xy.x, v->pat[i].img.xy.y, &v->pat[i].img);
			continue ;
		}
		tmp = v->m.map[v->pat[i].img.xy.y][v->pat[i].img.xy.x - 1];
		if (tmp == 0 || tmp == 4)
		{
			v->m.map[v->pat[i].img.xy.y][v->pat[i].img.xy.x] = 0;
			my_put_image(v, v->pat[i].img.xy.x, v->pat[i].img.xy.y, &v->s.f);
			v->pat[i].img.xy.x -= 1;
			v->m.map[v->pat[i].img.xy.y][v->pat[i].img.xy.x] = 5;
			my_put_image(v, v->pat[i].img.xy.x, v->pat[i].img.xy.y, &v->pat[i].img);
			continue ;
		}
	}
	return (0);
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

void	my_string_put(t_vars *v, int w, int h, char *str)
{
	int	wid;
	int	hei;

	wid = v->s.w.w * w + v->s.w.w / 2;
	hei = v->s.w.h * h - v->s.w.h / 2;
	mlx_string_put(v->mlx, v->win, wid, hei, 0x000000, str);
}

void	make_move(int len, char **move, int mcopy)
{
	int	i;
	int	tmp;

	i = -1;
	while (++i < len)
	{
		(*move)[i] = mcopy % 10 + '0';
		mcopy /= 10;
	}
	(*move)[len] = '\0';
	i = -1;
	while (++i < len / 2)
	{
		tmp = (*move)[i];
		(*move)[i] = (*move)[len - i - 1];
		(*move)[len - i - 1] = tmp;
	}
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
