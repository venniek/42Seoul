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
		ft_free(stack->order, stack->sum);
	if (i == 0)
		exit(0);
	if (i == 1)
		ft_putstr_fd("Error\n", 2);
	exit(1);
}

void add_order(t_stack *stack, char *str)
{
	(stack->sum)++;
	ft_stradd(stack, str);
}

int selec_sort(int *sorted, int argc)
{
	int i;
	int k;
	int min;
	int tmp;

	i = -1;
	while (i++ < argc / 2)
	{
		min = i;
		k = i + 1;
		while (k++ < argc)
		{
			if (sorted[min] > sorted[k])
				min = k;
		}
		tmp = sorted[min];
		sorted[min] = sorted[i];
		sorted[i] = tmp;
	}
	return (sorted[i - 1]);
}