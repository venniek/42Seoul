/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayeon <nayeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 02:25:52 by naykim            #+#    #+#             */
/*   Updated: 2022/04/09 20:03:16 by nayeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	parsing_minus(const char **str, t_flag *flag)
{
	flag->minus = 1;
	(*str)++;
}

void	parsing_zero(const char **str, t_flag *flag)
{
	flag->zero = 1;
	(*str)++;
}

void	parsing_width(const char **str, t_flag *flag, va_list *ap)
{
	int	n;

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

static void	parsing_prec_star(t_flag *flag, va_list *ap, const char **str)
{
	long long	n;

	n = va_arg(*ap, int);
	if (n < 0)
	{
		flag->sign = 2;
		n *= -1;
	}
	flag->prec = n;
	(*str)++;
}

void	parsing_prec(const char **str, t_flag *flag, va_list *ap)
{
	flag->dot = 1;
	(*str)++;
	if (**str == '-')
	{
		flag->sign = 1;
		(*str)++;
	}
	if (**str == '*')
		parsing_prec_star(flag, ap, str);
	else
	{
		if (ft_strchr(DIGIT, **str))
		{
			while (**str == '0')
				(*str)++;
			if (!(ft_strchr(DIGIT, **str)))
				flag->prec = 0;
			else
			{
				flag->prec = ft_atoi(*str);
				*str += ft_len(flag->prec, 10);
			}
		}
	}
}
