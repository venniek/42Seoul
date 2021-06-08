#include "push_swap.h"

int is_ascending(t_stack *stack)
{
	int i;

	i = stack->cnt - 1;
	while (i > 0)
	{
		if (stack->a[i] > stack->a[i - 1])
			return (1);
		i--;
	}
	return (0);
}

void ft_free(char **str, int cnt)
{
	int i;

	i = -1;
	while (++i < cnt)
	{
		free(str[i]);
		str[i] = 0;
	}
	free(str);
	str = 0; 
}

int ft_exit(t_stack *stack, int i)
{
	if (stack->a != 0)
	{
		free(stack->a);
		stack->a = 0;
	}
	if (stack->b != 0)
	{
		free(stack->b);
		stack->b = 0;
	}
	if (stack->order != 0)
	{
		free(stack->order);
		stack->order = 0;
	}
	if (i == 0)
		exit(0);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void add_order(t_stack *stack, char *str)
{
	(stack->sum)++;
	ft_stradd(stack, str);
}