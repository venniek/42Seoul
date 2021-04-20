/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 02:25:52 by naykim            #+#    #+#             */
/*   Updated: 2021/04/20 22:38:15 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		parsing_minus(const char **str, t_flag *flag)
{
	flag->minus = 1;
	(*str)++;
}

void		parsing_zero(const char **str, t_flag *flag)
{
	flag->zero = 1;
	(*str)++;
}

void		parsing_width(const char **str, t_flag *flag, va_list *ap)
{
	int n;

	if (**str == '*')
	{
		n = va_arg(*ap, int);
		if (n < 0)
		{
			n *= -1;
			flag->minus = 1;
		}
		flag->width = n;
		(*str)++;
	}
	else
	{
		flag->width = ft_atoi(*str);
		*str += ft_len(flag->width, 10);
	}
}

static void	parsing_prec_star(long long *n, t_flag *flag, va_list *ap)
{
	*n = va_arg(*ap, int);
	if (*n < 0)
	{
		*n *= -1;
		flag->sign = 2;
		flag->minus++;
	}
	flag->prec = *n;
}

void		parsing_prec(const char **str, t_flag *flag, va_list *ap)
{
	long long n;

	flag->dot = 1;
	(*str)++;
	if (**str == '*')
	{
		parsing_prec_str(&n, flag, ap);
		(*str)++;
	}
	else if (ft_strchr(DIGIT, **str))
	{
		while (**str == '0')
			(*str)++;
		if (!(ft_strchr(DIGIT, **str)))
			flag->prec = 0;
		else
		{
			n = ft_atoi(*str);
			if (n < 0)
			{
				n *= -1;
				flag->sign = 1;
				flag->minus = 1;
				(*str)++;
			}
			flag->prec = n;
			*str += ft_len(flag->prec, 10);
		}
	}
}
