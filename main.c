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
	return (ft_exit(&stack, 0));
}
