#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_stack stack;

	default_stack(&stack);
	if (argc <= 2)
		ft_exit(&stack, 2);
	argc--;
	make_stack(&stack, argc, argv);
	push_swap(&stack);
//	printf("final\n");
//	print_stack(&stack);
	return (ft_exit(&stack, 0));
}

void print_stack(t_stack *stack)
{
	printf("a: ");
	for (int i = 0; i < stack->ai; i++)
		printf("%3d ", stack->a[i]);
	printf("\nb: ");
	for (int i = 0; i < stack->bi; i++)
		printf("%3d ", stack->b[i]);
	printf("\n");
}
