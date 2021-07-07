/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:57:02 by naykim            #+#    #+#             */
/*   Updated: 2021/06/29 14:39:11 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (fd < 0 || s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

int		merge_order(t_stack *stack, char *str)
{
	if (stack->last == 0)
		return (0);
	if (ft_strcmp(stack->last, "sa") == 0 && ft_strcmp(str, "sb") == 0)
		return (1);
	if (ft_strcmp(stack->last, "sb") == 0 && ft_strcmp(str, "sa") == 0)
		return (1);
	if (ft_strcmp(stack->last, "ra") == 0 && ft_strcmp(str, "rb") == 0)
		return (1);
	if (ft_strcmp(stack->last, "rb") == 0 && ft_strcmp(str, "ra") == 0)
		return (1);
	if (ft_strcmp(stack->last, "rra") == 0 && ft_strcmp(str, "rrb") == 0)
		return (1);
	if (ft_strcmp(stack->last, "rrb") == 0 && ft_strcmp(str, "rra") == 0)
		return (1);
	return (0);
}

void	print_order(t_stack *stack)
{
	if (stack->last == 0)
		return ;
	ft_putstr_fd(stack->last, 1);
	ft_putstr_fd("\n", 1);
}

void	new_str(t_stack *stack, char *str)
{
	if (str[0] == 's')
		stack->last = ft_strdup("ss");
	else if (str[0] == 'r' && str[1] != 'r')
		stack->last = ft_strdup("rr");
	else if (str[1] == 'r')
		stack->last = ft_strdup("rrr");
}
