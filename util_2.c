#include "push_swap.h"

int is_ascending(int *a, int argc)
{
	int i;

	i = argc - 1;
	while (i > 0)
	{
		if (a[i] > a[i - 1])
			return (1);
		i--;
	}
	return (0);
}

int	ft_exit(int *a, int *b, int i)
{
	if (*a != 0)
	{
		free(a);
		*a = 0;
	}
	if (*b != 0)
	{
		free(b);
		*b = 0;
	}
	if (i == 0)
		exit(0);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}