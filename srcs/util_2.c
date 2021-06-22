/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:50:23 by naykim            #+#    #+#             */
/*   Updated: 2021/06/22 17:37:32 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_exit(t_stack *stack, int i)
{
	if (stack->a != 0)
		ft_intfree(stack->a);
	if (stack->b != 0)
		ft_intfree(stack->b);
	if (stack->sorted != 0)
		ft_intfree(stack->sorted);
	if (stack->pivot != 0)
		ft_intfree(stack->pivot);
	if (stack->last != 0)
	{
		free(stack->last);
		stack->last = 0;
	}
	if (i == 0)
		exit(0);
	if (i == 1)
		ft_putstr_fd("Error\n", 2);
	exit(1);
}

void ft_intfree(int *num)
{
	free(num);
	num = 0;
}

void	sort_sort(int *sort, int len)
{
	int	i;
	int	k;
	int	min;
	int	tmp;

	i = -1;
	while (++i < len - 1)
	{
		min = i;
		k = i;
		while (++k < len)
		{
			if (sort[min] > sort[k])
				min = k;
		}
		tmp = sort[min];
		sort[min] = sort[i];
		sort[i] = tmp;
	}
}

char		*ft_strdup(char *s)
{
	char	*dst;
	size_t	i;

	i = ft_strlen(s);
	if (!(dst = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int		ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		ft_strchr(const char *str, int a)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)str;
	while (i < ft_strlen(str) + 1)
	{
		if (s[i] == a)
			return (1);
		i++;
	}
	return (0);
}
