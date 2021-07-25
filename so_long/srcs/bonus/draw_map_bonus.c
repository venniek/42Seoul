#include "../../includes/so_long_bonus.h"

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
			else if (v->m.map[h][w] == 3)
				my_put_image(v, w, h, &v->s.e1);
			else if (v->m.map[h][w] == 4)
			{
				v->s.p.xy.x = w;
				v->s.p.xy.y = h;
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

void redraw_map(t_vars *v, int w, int h, int cur)
{
	my_put_image(v, w, h, &v->s.f);
	if (v->m.map[h][w] == 2 && cur % 2 == 0)
		my_put_image(v, w, h, &v->s.c1);
	else if (v->m.map[h][w] == 2 && cur % 2 == 1)
		my_put_image(v, w, h, &v->s.c2);
	else if (v->m.map[h][w] == 3 && cur % 2 == 0)
		my_put_image(v, w, h, &v->s.e1);
	else if (v->m.map[h][w] == 3 && cur % 2 == 1)
		my_put_image(v, w, h, &v->s.e2);
	else if (v->m.map[h][w] == 4)
		my_put_image(v, w, h, &v->s.p);
}
