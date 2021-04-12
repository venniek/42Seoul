/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_print_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 04:25:53 by naykim            #+#    #+#             */
/*   Updated: 2021/04/13 04:30:51 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	make_print_d(t_flag *flag, va_list *ap, t_pt *pt)
{
	long long	val;

	val = va_arg(*ap, int);
	if (val < 0)
	{
		pt->minus += 10;
		val *= -1;
	}
	pt->v_len = ft_len(val, 10);
	if (flag->sign == 2)
	{
		flag->dot = 0;
		flag->minus--;
	}
	if (flag->minus == 1)
		pt->minus += 1;
	if (flag->zero == 1 && flag->minus > 0)
		flag->zero = 0;
	if (flag->dot == 1)
	{
		if (val == 0 && flag->prec <= 0)
		{
			g_bt += ft_max(0, flag->width);
			while (flag->width-- > 0)
				ft_putchar(' ');
			return (0);
		}
		pt->z_len = ft_max(0, flag->prec - pt->v_len);
		pt->b_len = ft_max(0, flag->width - ft_max(flag->prec, pt->v_len) - pt->minus / 10);
	}
	else
	{
		if (flag->zero == 1)
			pt->z_len = ft_max(0, flag->width - pt->v_len - pt->minus / 10);
		else
			pt->b_len = ft_max(0, flag->width - pt->v_len - pt->minus / 10);
	}
	print_d(pt, val);
	return (0);
}

int	make_print_u(t_flag *flag, va_list *ap, t_pt *pt)
{
	unsigned int	val;

	val = va_arg(*ap, int);
	pt->v_len = ft_len(val, 10);
	if (flag->sign == 2)
	{
		flag->dot = 0;
		flag->minus--;
	}
	if (flag->minus == 1)
		pt->minus += 1;
	if (flag->zero == 1 && flag->minus > 0)
		flag->zero = 0;
	if (flag->dot == 1)
	{
		if (val == 0 && flag->prec <= 0)
		{
			g_bt += ft_max(0, flag->width);
			while (flag->width-- > 0)
				ft_putchar(' ');
			return (0);
		}
		pt->z_len = ft_max(0, flag->prec - pt->v_len);
		pt->b_len = ft_max(0, flag->width - ft_max(flag->prec, pt->v_len) - pt->minus / 10);
	}
	else
	{
		if (flag->zero == 1)
			pt->z_len = ft_max(0, flag->width - pt->v_len);
		else
			pt->b_len = ft_max(0, flag->width - pt->v_len);
	}
	print_u(pt, val);
	return (0);
}

int	make_print_x(t_flag *flag, va_list *ap, t_pt *pt)
{
	unsigned int	val;

	val = va_arg(*ap, int);
	pt->v_len = ft_len(val, 16);
	if (flag->sign == 2)
	{
		flag->dot = 0;
		flag->minus--;
	}
	if (flag->minus == 1)
		pt->minus += 1;
	if (flag->zero == 1 && flag->minus > 0)
		flag->zero = 0;
	if (flag->dot == 1)
	{
		if (val == 0 && flag->prec <= 0)
		{
			g_bt += ft_max(0, flag->width);
			while (flag->width-- > 0)
				ft_putchar(' ');
			return (0);
		}
		pt->z_len = ft_max(0, flag->prec - pt->v_len);
		pt->b_len = ft_max(0, flag->width - ft_max(flag->prec, pt->v_len) - pt->minus / 10);
	}
	else
	{
		if (flag->zero == 1)
			pt->z_len = ft_max(0, flag->width - pt->v_len);
		else
			pt->b_len = ft_max(0, flag->width - pt->v_len);
	}
	print_x(pt, val, flag->type);
	return (0);
}