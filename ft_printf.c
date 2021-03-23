/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:29:34 by naykim            #+#    #+#             */
/*   Updated: 2021/03/19 16:21:31 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_printf(const char *format, ...)
{
	va_list ap;
	int bt;

	va_start(ap, str);
	while (*format)
	{
		if (*format != '%')
			bt = write(1, *format++, 1);
		else;

	}

	va_end(ap);
	return (bt);
}
