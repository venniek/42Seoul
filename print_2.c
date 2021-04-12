/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 04:36:59 by naykim            #+#    #+#             */
/*   Updated: 2021/04/13 04:37:07 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_d(t_pt *pt, long long val)
{
	int i;
	int k;

	i = -1;
	k = -1;
	if (pt->minus % 10 == 0)
	{
		while (++i < pt->b_len)
			ft_putchar(' ');
		if (pt->minus / 10 == 1)
			ft_putchar('-');
		while (++k < pt->z_len)
			ft_putchar('0');
		ft_putnbr(val);
	}
	else
	{
		if (pt->minus / 10 == 1)
			ft_putchar('-');
		while (++k < pt->z_len)
			ft_putchar('0');
		ft_putnbr(val);
		while (++i < pt->b_len)
			ft_putchar(' ');
	}
	g_bt += pt->b_len + pt->z_len + pt->v_len + pt->minus / 10;
}

void	print_u(t_pt *pt, unsigned int val)
{
	int i;
	int k;

	i = -1;
	k = -1;
	if (pt->minus % 10 == 0)
	{
		while (++i < pt->b_len)
			ft_putchar(' ');
		if (pt->minus / 10 == 1)
			ft_putchar('-');
		while (++k < pt->z_len)
			ft_putchar('0');
		ft_putnbr(val);
	}
	else
	{
		if (pt->minus / 10 == 1)
			ft_putchar('-');
		while (++k < pt->z_len)
			ft_putchar('0');
		ft_putnbr(val);
		while (++i < pt->b_len)
			ft_putchar(' ');
	}
	g_bt += pt->b_len + pt->z_len + pt->v_len + pt->minus / 10;
}

void	print_x(t_pt *pt, unsigned int val, char c)
{
	int i;
	int k;

	i = -1;
	k = -1;
	if (pt->minus % 10 == 0)
	{
		while (++i < pt->b_len)
			ft_putchar(' ');
		if (pt->minus / 10 == 1)
			ft_putchar('-');
		while (++k < pt->z_len)
			ft_putchar('0');
		ft_putnbr_hex(val, c);
	}
	else
	{
		if (pt->minus / 10 == 1)
			ft_putchar('-');
		while (++k < pt->z_len)
			ft_putchar('0');
		ft_putnbr_hex(val, c);
		while (++i < pt->b_len)
			ft_putchar(' ');
	}
	g_bt += pt->b_len + pt->z_len + pt->v_len + pt->minus / 10;
}
