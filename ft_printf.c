/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:29:34 by naykim            #+#    #+#             */
/*   Updated: 2021/03/22 18:30:12 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_printf(const char *str, ...)
{
	va_list ap;
	int bt;

	bt = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
			bt += write(1, *str++, 1);
		else
			;

	}

	va_end(ap);
	return (bt);
}
