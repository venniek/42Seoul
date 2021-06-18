#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_stack stack;

	default_stack(&stack);
	if (argc <= 2)
		ft_exit(&stack, 2);
	argc--;
	make_stack(&stack, argc, argv);
/*		printf("a: ");
	for (int i = stack.ai - 1; i >= 0; i--)
		printf("%3d ", stack.a[i]);
	printf("\nb: ");
	for (int i = stack.bi - 1; i >= 0; i--)
		printf("%3d ", stack.b[i]);
	printf("\n");*/
	push_swap(&stack);
	printf("%d", stack.total);
	return (ft_exit(&stack, 0));
}
