/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:15:28 by naykim            #+#    #+#             */
/*   Updated: 2021/04/05 23:06:05 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define DIGIT "0123456789"
# define HEX_L "0123456789abcdef"
# define HEX_U "0123456789ABCDEF"
# define TYPE "cspdiuxX%"

typedef struct s_flag
{
	int minus;
	int zero;
	int width;
	int star;
	int dot;
	int prec;
	char type;
} t_flag;

int bt;




#endif
