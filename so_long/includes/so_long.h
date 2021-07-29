/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 02:58:35 by naykim            #+#    #+#             */
/*   Updated: 2021/07/29 02:58:37 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 300
# endif

# define K_ESC 53
# define K_LEFT_A 0
# define K_RIGHT_D 2
# define K_UP_W 13
# define K_DOWN_S 1

typedef struct s_xy
{
	int	x;
	int	y;
}	t_xy;

typedef struct s_map
{
	int	w;
	int	h;
	int	c;
	int	p;
	int	e;
	int	**map;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		w;
	int		h;
	int		bpp;
	int		len;
	int		endian;
	t_xy	xy;
}	t_img;

typedef struct s_sprite
{
	t_img	w;
	t_img	col;
	t_img	f;
	t_img	c1;
	t_img	p;
	t_img	e;
}	t_sprite;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			move;
	int			score;
	int			collision;
	t_map		m;
	t_sprite	s;
}	t_vars;

char			*ft_strjoin(char **s1, char *s2);
unsigned int	ft_strlen(char *s);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strdup(char *s);

int				ft_newline(const char *save);
int				update_save(char **save, int index, char **line);
int				read_done(char **line, char **save, int size);
int				get_next_line(int fd, char **line);

int				ft_max(int a, int b);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
int				ft_strcmp(const char *s1, const char *s2, t_vars *v);
int				is_ber(char *str);

void			default_map(t_vars *v);
int				char_to_i(char a, t_vars *v);
void			make_map(char *av[], t_vars *v);
void			get_info(char *av[], t_vars *v);
void			make_info(char *av[], t_vars *v);

void			make_all(t_vars *v);
void			xpm_to_image(t_vars *v, t_img *img);

void			draw_map(t_vars *v);
void			draw_sprite(t_vars *v);
void			my_put_image(t_vars *v, int w, int h, t_img *img);

void			map_error(t_vars *v, int a);
void			check_map_error(t_vars *v);
void			check_map_wall(t_vars *v);
int				check_collision(t_vars *v, int kc);
void			no_collision(t_vars *v, t_xy *xy);

int				ft_keypress(int keycode, t_vars *v);
int				ft_click(t_vars *v);
void			ft_exit(t_vars *v, int a);
void			finish_game(t_vars *v);

#endif
