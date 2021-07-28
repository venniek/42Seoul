/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 02:22:29 by naykim            #+#    #+#             */
/*   Updated: 2021/07/29 02:22:30 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	ft_abs(int a)
{
	if (a > 0)
		return (a);
	return (-1 * a);
}

int	char_to_i(char a, t_vars *v)
{
	if (a == '0')
		return (0);
	if (a == '1')
		return (1);
	if (a == 'C')
	{
		v->m.c++;
		return (2);
	}
	if (a == 'E')
	{
		v->m.e++;
		return (3);
	}
	if (a == 'P')
	{
		v->m.p++;
		return (4);
	}
	map_error(v, 7);
	return (-1);
}
