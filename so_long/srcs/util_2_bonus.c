/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 02:22:38 by naykim            #+#    #+#             */
/*   Updated: 2021/07/29 02:22:39 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (fd < 0 || s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

int	ft_strcmp(const char *s1, const char *s2, t_vars *v)
{
	size_t	i;

	i = 0;
	if (!s1)
		map_error(v, 8);
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (s2[i] == '\0')
		return (0);
	else
		return (-s2[i]);
}

void	what_is_filename(char **filename, t_vars *v, t_img *i)
{
	int	k;

	k = -1;
	if (i == &v->s.w)
		*filename = ft_strdup("./imgs/cloud_wall.xpm");
	else if (i == &v->s.col)
		*filename = ft_strdup("./imgs/column.xpm");
	else if (i == &v->s.f)
		*filename = ft_strdup("./imgs/floor.xpm");
	else if (i == &v->s.c1)
		*filename = ft_strdup("./imgs/ball_down.xpm");
	else if (i == &v->s.c2)
		*filename = ft_strdup("./imgs/ball_up.xpm");
	else if (i == &v->s.p)
		*filename = ft_strdup("./imgs/woody.xpm");
	else if (i == &v->s.e1)
		*filename = ft_strdup("./imgs/door_open.xpm");
	else if (i == &v->s.e2)
		*filename = ft_strdup("./imgs/door_close.xpm");
	else if (i >= &v->pat[0] && i <= &v->pat[4])
		*filename = ft_strdup("./imgs/lotso.xpm");
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
