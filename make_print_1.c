/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_print_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 04:20:33 by naykim            #+#    #+#             */
/*   Updated: 2021/04/13 04:25:07 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	make_print_c(t_flag *flag, va_list *ap, t_pt *pt)
{
	char	val;

	val = va_arg(*ap, int);
	if (flag->zero == 1 || flag->prec != -1)
		return (UNDEFINED);
	if (flag->minus == 1)
		pt->minus = 1;
	if (flag->width != -1)
		pt->b_len = ft_max(0, flag->width - 1);
	pt->v_len = 1;
	print_c(pt, val);
	return (0);
}

int	make_print_s(t_flag *flag, va_list *ap, t_pt *pt)
{
	char	*val;

	val = va_arg(*ap, char *);
	if (val == NULL)
		val = "(null)";
	if (flag->zero == 1)
		return (UNDEFINED);
	if (flag->sign == 1)
		return (INVALID);
	if (flag->sign == 2)
	{
		flag->dot = 0;
		flag->minus--;
		pt->v_len = ft_strlen(val);
	}
	if (flag->minus == 1)
		pt->minus += 1;
	if (flag->zero == 1 && flag->minus > 0)
		flag->zero = 0;
	else if (flag->dot == 1 && flag->prec <= 0)
		pt->v_len = 0;
	else if (flag->dot == 1)
		pt->v_len = ft_min(ft_strlen(val), flag->prec);
	else
		pt->v_len = ft_strlen(val);
	if (pt->v_len < flag->width)
		pt->b_len = flag->width - pt->v_len;
	print_s(pt, val);
	return (0);
}

int	make_print_p(t_flag *flag, va_list *ap, t_pt *pt)
{
	unsigned long	val;

	if (flag->prec != -1 || flag->zero == 1)
		return (UNDEFINED);
	val = (unsigned long)va_arg(*ap, void *);
	if (val == (unsigned long)NULL && flag->dot == 1)
		pt->minus = -1;
	else
	{
		pt->v_len = ft_len(val, 16);
		if (flag->minus == 1)
			pt->minus = 1;
		pt->b_len = ft_max(0, flag->width - pt->v_len - 2);
	}
	print_p(pt, val);
	return (0);
}

int	make_print_per(t_flag *flag, t_pt *pt)
{
	char	val;

	val = '%';
	if (flag->sign == 1)
		return (INVALID);
	if (flag->zero == 1 && flag->minus == 0)
		pt->z_len = ft_max(0, flag->width - 1);
	else
	{
		if (flag->minus == 1)
			pt->minus = 1;
		pt->b_len = ft_max(0, flag->width - 1);
	}
	print_per(pt, val);
	return (0);
}