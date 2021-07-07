/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:55:26 by naykim            #+#    #+#             */
/*   Updated: 2021/06/22 20:12:20 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		main(int argc, char *argv[])
{
	t_stack stack;

	default_stack(&stack);
	if (argc <= 1)
		ft_exit(&stack, 0);
	make_stack(&stack, argc, argv);
	if (stack.cnt == 1)
		ft_exit(&stack, 0);
	if (check_sort(&stack) == 0)
		ft_exit(&stack, 0);
	if (stack.cnt <= 5)
		push_swap_under5(&stack);
	else
		push_swap(&stack);
	print_order(&stack);
	ft_exit(&stack, 0);
}
