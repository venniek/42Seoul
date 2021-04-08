#include "printf.h"

void parsing_minus(const char **str, t_flag *flag)
{
	flag->minus = 1;
	*str++;
	return ;
}

void parsing_zero(const char **str, t_flag *flag)
{
	flag->zero = 1;
	*str++;
	return ;
}

void parsing_width(const char **str, t_flag *flag)
{
	flag->width = ft_atoi(*str);
	*str += ft_len(flag->width);
	return ;
}


void parsing_star(const char **str, t_flag *flag, va_list *ap)
{
	flag->width = va_arg(*ap, int); //minus? plus?
	*str++;
	return ;
}


void parsing_prec(const char **str, t_flag *flag, va_list *ap)
{
	flag->dot = 1;
	*str++;
	if (!ft_strchr(DIGIT, **str))
	{
		flag->prec = ft_atoi(*str);
		*str += ft_len(flag->prec);
	}
	else if (**str == '*')
	{
		flag->prec = va_arg(*ap, int);
		*str++;
	}
	return ;
}
