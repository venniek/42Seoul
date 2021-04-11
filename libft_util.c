#include "printf.h"

long long ft_min(size_t a, long long b)
{
	if ((long long)a > b)
		return (b);
	else
		return (a);
}
size_t ft_len(unsigned int n)
{
	size_t i;

	i = 0;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{

	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n >= 10)
			ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
}

char *ft_strchr(char *str, int a)
{
	size_t i;
	char *s;

	i = 0;
	s = str;
	while (i < ft_strlen(str) + 1)
	{
		if (s[i] == a)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

int	ft_atoi(const char *str)
{
	int	atoi;
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	atoi = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			atoi = atoi * 10 + str[i] - '0';
		else
			break ;
		i++;
	}
	return (sign * atoi);
}