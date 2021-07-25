#include "../../includes/so_long_bonus.h"

void	make_all(t_vars *v)
{
	int	w;
	int	h;
	int	bpp;

	v->mlx = mlx_init();
	xpm_to_image(v, &v->s.w);
	xpm_to_image(v, &v->s.col);
	xpm_to_image(v, &v->s.f);
	xpm_to_image(v, &v->s.c1);
	xpm_to_image(v, &v->s.c2);
	xpm_to_image(v, &v->s.p);
	xpm_to_image(v, &v->s.e1);
	xpm_to_image(v, &v->s.e2);
	w = v->m.w;
	h = v->m.h;
	bpp = v->s.w.bpp;
	v->win = mlx_new_window(v->mlx, w * bpp, h * bpp, "Bye Andy");
}

void	xpm_to_image(t_vars *v, t_img *i)
{
	char	*filename;

	if (i == &v->s.w)
		filename = ft_strdup("./imgs/cloud_wall.xpm");
	else if (i == &v->s.col)
		filename = ft_strdup("./imgs/column.xpm");
	else if (i == &v->s.f)
		filename = ft_strdup("./imgs/floor.xpm");
	else if (i == &v->s.c1)
		filename = ft_strdup("./imgs/ball_down.xpm");
	else if (i == &v->s.c2)
		filename = ft_strdup("./imgs/ball_up.xpm");
	else if (i == &v->s.p)
		filename = ft_strdup("./imgs/woody.xpm");
	else if (i == &v->s.e1)
		filename = ft_strdup("./imgs/door_open.xpm");
	else if (i == &v->s.e2)
		filename = ft_strdup("./imgs/door_close.xpm");
	i->img = mlx_xpm_file_to_image(v->mlx, filename, &(i->w), &(i->h));
	i->addr = mlx_get_data_addr(i->img, &(i->bpp), &(i->len), &(i->endian));
	free(filename);
	filename = 0;
}
