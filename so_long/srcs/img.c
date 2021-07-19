#include "../ft_so_long.h"

void make_all(t_vars *v)
{
	v->mlx = mlx_init();
	//wall
	v->s.wall.img = mlx_xpm_file_to_image(v->mlx, "./imgs/cloud_wall.xpm", &(v->s.wall.width), &(v->s.wall.height));
	v->s.wall.addr = mlx_get_data_addr(v->s.wall.img, &(v->s.wall.bpp), &(v->s.wall.line_length), &(v->s.wall.endian));
	//column
	v->s.column.img = mlx_xpm_file_to_image(v->mlx, "./imgs/column.xpm", &(v->s.column.width), &(v->s.column.height));
	v->s.column.addr = mlx_get_data_addr(v->s.column.img, &(v->s.column.bpp), &(v->s.column.line_length), &(v->s.column.endian));

	//floor
	v->s.floor.img = mlx_xpm_file_to_image(v->mlx, "./imgs/floor.xpm", &(v->s.floor.width), &(v->s.floor.height));
	v->s.floor.addr = mlx_get_data_addr(v->s.floor.img, &(v->s.floor.bpp), &(v->s.floor.line_length), &(v->s.floor.endian));
	//escape
	v->s.escape.img = mlx_xpm_file_to_image(v->mlx, "./imgs/sunnyside.xpm", &(v->s.escape.width), &(v->s.escape.height));
	v->s.escape.addr = mlx_get_data_addr(v->s.escape.img, &(v->s.escape.bpp), &(v->s.escape.line_length), &(v->s.escape.endian));
	//collect
	v->s.collect1.img = mlx_xpm_file_to_image(v->mlx, "./imgs/ball_down.xpm", &(v->s.collect1.width), &(v->s.collect1.height));
	v->s.collect1.addr = mlx_get_data_addr(v->s.collect1.img, &(v->s.collect1.bpp), &(v->s.collect1.line_length), &(v->s.collect1.endian));
	v->s.collect2.img = mlx_xpm_file_to_image(v->mlx, "./imgs/ball_up.xpm", &(v->s.collect2.width), &(v->s.collect2.height));
	v->s.collect2.addr = mlx_get_data_addr(v->s.collect2.img, &(v->s.collect2.bpp), &(v->s.collect2.line_length), &(v->s.collect2.endian));
	
	//player
	v->s.player.img = mlx_xpm_file_to_image(v->mlx, "./imgs/woody.xpm", &(v->s.player.width), &(v->s.player.height));
	v->s.player.addr = mlx_get_data_addr(v->s.player.img, &(v->s.player.bpp), &(v->s.player.line_length), &(v->s.player.endian));
	v->win = mlx_new_window(v->mlx, v->m.width * v->s.wall.bpp, v->m.height * v->s.wall.bpp, "Bye Andy");

}