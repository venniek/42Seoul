/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:29:34 by naykim            #+#    #+#             */
/*   Updated: 2021/04/06 19:07:15 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void parsing_str(const char **str, va_list *ap)
{
	t_flag flag;

	(*str)++;
	if (**str == '-')
		parsing_minus(str, ap);
	else if (**str == '0')
		parsing_zero(str, ap);
	else if (!ft_strchr(DIGIT, **str))
		parsing_width(str, ap);
	else if (**str == '*')
		parsing_star(str, ap);
	else if (**str == '.')
		parsing_prec(str, ap);

			}

int ft_printf(const char *str, ...)
{
	va_list ap;
	
	va_start(ap, str);
	bt = 0;
	while (*str != '\0')
	{
		if (*str != '%')
			bt += write(1, *str++, 1);
		else
			parsing_str(&str, &ap);
	}
	va_end(ap);
	return (bt);
}
