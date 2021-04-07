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


//-------ft_printf
void parsing_str(const char **str, va_list *ap);
int ft_printf(const char *str, ...);

//-------parsing_all
void parsing_minus(const char **str, t_flag *flag);
void parsing_zero(const char **str, t_flag *flag);
void parsing_width(const char **str, t_flag *flag);
void parsing_star(const char **str, t_flag *flag, va_list *ap);
void parsing_prec(const char **str, t_flag *flag, va_list *ap);

//-------libft_util1
size_t ft_strlen(char *str);
char *ft_strchr(const char *str, int a);

//-------libft_util2

#endif
