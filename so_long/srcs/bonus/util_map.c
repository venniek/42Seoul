#include "../../includes/so_long_bonus.h"

int	ft_animation(t_vars *v)
{
	int	h;
	int	w;
	int	cur;

	cur = (int)(time(NULL) - v->start);
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
