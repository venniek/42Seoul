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
	push_swap(&stack);
//	print(&stack);    //delete!
	i = -1;
	while (++i < stack.cnt)
		ft_putstr_fd(stack.order[i], 1);
	return (ft_exit(&stack, 0));
}