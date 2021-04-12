/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:29:34 by naykim            #+#    #+#             */
/*   Updated: 2021/04/07 16:53:31 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int g_bt;

static void flag_all_new(t_flag *flag)
{
	flag->minus = 0;
	flag->zero = 0;
	flag->width = -1;
	flag->dot = 0;
	flag->sign = 0;
	flag->prec = -1;
	flag->type = '\0';
}

static void pt_all_new(t_pt *pt)
{
	pt->b_len = 0;
	pt->z_len = 0;
	pt->v_len = 0;
	pt->minus = 0;
}

static int make_print(t_flag *flag, va_list *ap)
{
	t_pt pt;

	pt_all_new(&pt);
	if (flag->type == 'c')
		return (make_print_c(flag, ap, &pt));
	if (flag->type == 's')
		return (make_print_s(flag, ap, &pt));
//	if (flag->type == 'p')
//		return (make_print_p(flag, ap, &pt));
	if (flag->type == 'd' || flag->type == 'i')
		return (make_print_d(flag, ap, &pt));
/*	if (flag->type == 'u')
		return (make_print_u(flag, ap, &pt));
	if (flag->type == 'x' || flag->type == 'X')
		return (make_print_x(flag, ap, &pt));
*/	if (flag->type == '%')
		return (make_print_per(flag, &pt));
	else
		return (ERROR);
}

static int parsing_str(const char **str, va_list *ap)
{
	t_flag flag;

	flag_all_new(&flag);
	(*str)++;
	while (!ft_strchr(TYPE, **str))
	{
		if (**str == '-')
			parsing_minus(str, &flag);
		else if (**str == '0')
			parsing_zero(str, &flag);
		else if (ft_strchr(DIGIT, **str) || **str == '*')
			parsing_width(str, &flag, ap);
		else if (**str == '.')
			parsing_prec(str, &flag, ap);
	}
	flag.type = **str;
	(*str)++;
	return (make_print(&flag, ap));
}

int ft_printf(const char *str, ...)
{
	va_list ap;
	
	va_start(ap, str);
	g_bt = 0;
	while (*str != '\0')
	{
		if (*str != '%')
		{
			ft_putchar(*str);
			g_bt++;
			str++;
		}
		else
		{
			if (parsing_str(&str, &ap) == -1)
				return (ERROR);
		}
	}
	va_end(ap);
	return (g_bt);
}
