#include "push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	if (fd < 0 || s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

long long ft_atoi(const char *str)
{
	long long atoi;
	int i;
	int sign;

	i = 0;
	sign = 1;
	atoi = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			atoi = atoi * 10 + str[i] - '0';
		else
			return (-1);
		i++;
	}
	return (sign * atoi);
}

void ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void ft_stradd(t_stack *stack, char *str)
{
	char			**new;
	int i;

	if (str == 0)
		return ;
	new = (char **)malloc(sizeof(char *) * stack->sum);
	i = -1;
	while (++i < stack->sum - 1)
	{
		new[i] = (char *)malloc(sizeof(char) * 4);
		ft_strcpy(new[i], stack->order[i]);
	}
	new[i] = (char *)malloc(sizeof(char) * 4);
	ft_strcpy(new[i], str);
	ft_free(stack->order, i);
	stack->order = new;
}