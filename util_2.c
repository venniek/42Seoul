#include "push_swap.h"

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
		return 0;
	else
		ft_putstr("Error\n");
		
	exit(0);
}