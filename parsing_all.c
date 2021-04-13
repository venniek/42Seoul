/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 02:25:52 by naykim            #+#    #+#             */
/*   Updated: 2021/04/13 05:00:40 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		parsing_minus(const char **str, t_flag *flag)
{
	flag->minus = 1;
	(*str)++;
	return ;
}

void		parsing_zero(const char **str, t_flag *flag)
{
	flag->zero = 1;
	(*str)++;
	return ;
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
	return ;
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
	return ;
}

void		parsing_prec_str(long long *n, t_flag *flag, va_list *ap)
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
