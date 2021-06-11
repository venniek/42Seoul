#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_stack stack;
	int i;

	default_stack(&stack);
	if (argc <= 2)
		ft_exit(&stack, 2);
	argc--;
	make_stack(&stack, argc, argv);
	printf("\nbefore\n");
	print_stack(&stack);    //delete!
	push_swap(&stack);
	printf("\nafter\n");
	print_stack(&stack);    //delete!
	i = -1;
	while (++i < stack.sum)
		ft_putstr_fd(stack.order[i], 1);
	return (ft_exit(&stack, 0));
}


void print_stack(t_stack *stack)
{
	printf("a: ");
	for (int i = 0; i < stack->ai; i++)
		printf("%-4d", stack->a[i]);
	printf("\nb: ");
	for (int i = 0; i < stack->bi; i++)
		printf("%-4d", stack->b[i]);
	printf("\nsum: %d\n\n", stack->sum);
}