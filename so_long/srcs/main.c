/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:24:43 by naykim            #+#    #+#             */
/*   Updated: 2021/07/28 12:24:47 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_vars	v;

	default_map(&v);
	if (ac < 2)
	{
		ft_putstr_fd("no maps\n", 2);
		ft_putstr_fd("Error\n", 2);
		ft_exit(&v, 1);
	}
	if (!ft_strcmp(av[1], "maps", &v) || !ft_strcmp(av[1], "maps/", &v))
		map_error(&v, 8);
	if (ft_strlen(av[1]) < 5 || is_ber(av[1]) == 0)
		map_error(&v, 8);
	make_map(av, &v);
	check_map_error(&v);
	make_all(&v);
	draw_map(&v);
	draw_sprite(&v);
	mlx_hook(v.win, 2, 1L << 0, ft_keypress, &v);
	mlx_hook(v.win, 17, 0, ft_click, &v);
	mlx_loop(v.mlx);
	return (0);
}
