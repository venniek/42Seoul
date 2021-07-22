#include "../includes/so_long.h"

void	map_repeat(t_vars *v)
{
	if (v->collision == 0)
		printf("move: %d\n", v->move);
	draw_map(v);
	draw_sprite(v);
}

void	draw_map(t_vars *v)
{
	int	h;
	int	w;

	h = -1;
	while (++h < v->m.h)
	{
		w = -1;
		while (++w < v->m.w)
		{
			my_put_image(v, w, h, &v->s.f);
			if (v->m.map[h][w] == 1)
			{
				if (h == 0 || h == v->m.h - 1 || w == 0 || w == v->m.w - 1)
					my_put_image(v, w, h, &v->s.w);
				else
					my_put_image(v, w, h, &v->s.col);
			}
		}
	}
}

void	draw_sprite(t_vars *v)
{
	int	h;
	int	w;

	h = -1;
	while (++h < v->m.h)
	{
		w = -1;
		while (++w < v->m.w)
		{
			if (v->m.map[h][w] == 2)
				my_put_image(v, w, h, &v->s.c1);
			if (v->m.map[h][w] == 3)
				my_put_image(v, w, h, &v->s.e);
			if (v->m.map[h][w] == 4)
			{
				v->s.p.x = w;
				v->s.p.y = h;
				my_put_image(v, w, h, &v->s.p);
			}
		}
	}
}

void	my_put_image(t_vars *v, int w, int h, t_img *img)
{
	int	wid;
	int	hei;

	wid = img->w;
	hei = img->h;
	mlx_put_image_to_window(v->mlx, v->win, img->img, w * wid, h * hei);
}
