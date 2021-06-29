/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:36:19 by naykim            #+#    #+#             */
/*   Updated: 2021/06/29 14:37:34 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		do_order_checker(t_stack *stack, char *str)
{
	if (ft_strcmp(str, "pa") == 0 || ft_strcmp(str, "pb") == 0)
		push(stack, str[1]);
	else if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "sb") == 0)
		swap(stack, str[1]);
	else if (ft_strcmp(str, "ra") == 0 || ft_strcmp(str, "rb") == 0)
		rotate(stack, str[1]);
	else if (ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrb") == 0)
		reverse(stack, str[2]);
	else if (ft_strcmp(str, "ss") == 0)
	{
		swap(stack, 'a');
		swap(stack, 'b');
	}
	else if (ft_strcmp(str, "rr") == 0)
	{
		rotate(stack, 'a');
		rotate(stack, 'b');
	}
	else if (ft_strcmp(str, "rrr") == 0)
	{
		reverse(stack, 'a');
		reverse(stack, 'b');
	}
	else
		ft_exit(stack, 1);
}

int			main(int argc, char *argv[])
{
	t_stack	stack;
	int		ret;
	char	*line;

	line = 0;
	default_stack(&stack);
	if (argc <= 1)
		ft_exit(&stack, 0);
	make_stack(&stack, argc, argv);
	while ((ret = get_next_line(0, &line)) > 0)
	{
		do_order_checker(&stack, line);
		free(line);
		line = 0;
	}
	if (check_sort(&stack) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_exit(&stack, 0);
}
