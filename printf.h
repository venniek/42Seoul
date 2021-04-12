/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:15:28 by naykim            #+#    #+#             */
/*   Updated: 2021/04/11 11:50:56 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# define DIGIT "0123456789"
# define HEX_L "0123456789abcdef"
# define HEX_U "0123456789ABCDEF"
# define TYPE "cspdiuxX%"

# define ERROR -1
# define UNDEFINED -1
# define INVALID -1

typedef struct s_flag
{
	char minus;
	char zero;
	long long width;
	char dot;
	char sign;
	long long prec;
	char type;
} t_flag;

typedef struct s_pt
{
	int b_len;
	int z_len;
	int v_len;
	char minus;
}	t_pt;

extern int g_bt;

//-------ft_printf
int ft_printf(const char *str, ...);

//-------parsing_all
void parsing_minus(const char **str, t_flag *flag);
void parsing_zero(const char **str, t_flag *flag);
void parsing_width(const char **str, t_flag *flag, va_list *ap);
void parsing_prec(const char **str, t_flag *flag, va_list *ap);

//-------libft_util1
size_t ft_strlen(char *str);
size_t ft_len(unsigned long n, int base);
char *ft_strchr(char *str, int a);
int ft_atoi(const char *str);

//-------libft_util2
void ft_putchar(char c);
void ft_putstr(char *s);
void ft_putnbr(long long n);
void ft_putnbr_hex(unsigned long n, char c);
long long ft_min(size_t a, long long b);
long long ft_max(long long a, long long b);

//-------make_print_1
int make_print_c(t_flag *flag, va_list *ap, t_pt *pt);
int make_print_s(t_flag *flag, va_list *ap, t_pt *pt);
int make_print_d(t_flag *flag, va_list *ap, t_pt *pt);
int make_print_p(t_flag *flag, va_list *ap, t_pt *pt);
int make_print_u(t_flag *flag, va_list *ap, t_pt *pt);
int make_print_x(t_flag *flag, va_list *ap, t_pt *pt);
int make_print_per(t_flag *flag, t_pt *pt);

//-------print_1
void print_c(t_pt *pt, char val);
void print_s(t_pt *pt, char *val);
void print_d(t_pt *pt, long long val);
void print_p(t_pt *pt, unsigned long val);
void print_u(t_pt *pt, unsigned int val);
void print_x(t_pt *pt, unsigned int val);
void print_per(t_pt *pt, char val);

#endif
