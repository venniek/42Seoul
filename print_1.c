/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 04:31:10 by naykim            #+#    #+#             */
/*   Updated: 2021/04/13 04:39:43 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_c(t_pt *pt, char val)
{
	int	i;

	i = -1;
	if (pt->minus == 0)
	{
		while (++i < pt->b_len)
			ft_putchar(' ');
		ft_putchar(val);
	}
	else
	{
		ft_putchar(val);
		while (++i < pt->b_len)
			ft_putchar(' ');
	}
	g_bt += pt->b_len + pt->v_len;
}

void	print_s(t_pt *pt, char *val)
{
	int i;
	int k;

	i = -1;
	k = -1;
	if (pt->minus == 0)
	{
		while (++i < pt->b_len)
			ft_putchar(' ');
		while (++k < pt->v_len)
			ft_putchar(val[k]);
	}
	else
	{
		while (++k < pt->v_len)
			ft_putchar(val[k]);
		while (++i < pt->b_len)
			ft_putchar(' ');
	}
	g_bt += pt->b_len + pt->v_len;
}

void	print_p(t_pt *pt, unsigned long val)
{
	int i;

	i = -1;
	if (pt->minus == -1)
		ft_putstr("0x");
	else
	{
		if (pt->minus == 0)
		{
			while (++i < pt->b_len)
				ft_putchar(' ');
			ft_putstr("0x");
			ft_putnbr_hex(val, 'p');
		}
		else
		{
			ft_putstr("0x");
			ft_putnbr_hex(val, 'p');
			while (++i < pt->b_len)
				ft_putchar(' ');
		}
	}
	g_bt += pt->v_len + pt->b_len + 2;
}

void	print_per(t_pt *pt, char val)
{
	int i;

	i = -1;
	if (pt->z_len > 0)
	{
		while (++i < pt->z_len)
			ft_putchar('0');
		ft_putchar(val);
	}
	else
	{
		if (pt->minus == 0)
		{
			while (++i < pt->b_len)
				ft_putchar(' ');
			ft_putchar(val);
		}
		else
		{
			ft_putchar(val);
			while (++i < pt->b_len)
				ft_putchar(' ');
		}
	}
	g_bt += pt->z_len + pt->b_len + 1;
}
