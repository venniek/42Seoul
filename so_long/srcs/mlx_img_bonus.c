/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:47:42 by naykim            #+#    #+#             */
/*   Updated: 2021/07/29 02:22:13 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	make_all(t_vars *v)
{
	int	w;
	int	h;
	int	bpp;
	int	i;

	i = -1;
	v->mlx = mlx_init();
	xpm_to_image(v, &v->s.w);
	xpm_to_image(v, &v->s.col);
	xpm_to_image(v, &v->s.f);
	xpm_to_image(v, &v->s.c1);
	xpm_to_image(v, &v->s.c2);
	xpm_to_image(v, &v->s.p);
	xpm_to_image(v, &v->s.e1);
	xpm_to_image(v, &v->s.e2);
	while (++i < 5)
		xpm_to_image(v, &v->pat[i]);
	w = v->m.w;
	h = v->m.h;
	bpp = v->s.w.bpp;
	v->win = mlx_new_window(v->mlx, w * bpp, h * bpp, "Bye Andy");
}

void	xpm_to_image(t_vars *v, t_img *i)
{
	char	*filename;
	int		k;

	k = -1;
	what_is_filename(&filename, v, i);
	i->img = mlx_xpm_file_to_image(v->mlx, filename, &(i->w), &(i->h));
	i->addr = mlx_get_data_addr(i->img, &(i->bpp), &(i->len), &(i->endian));
	free(filename);
	filename = 0;
}

void	my_put_image(t_vars *v, int w, int h, t_img *img)
{
	int	wid;
	int	hei;

	wid = img->w;
	hei = img->h;
	mlx_put_image_to_window(v->mlx, v->win, img->img, w * wid, h * hei);
}
