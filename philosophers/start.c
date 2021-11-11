#include "philosophers.h"

int free_total(t_total *total, int i)
{
	if (total->fork)
	{
		free(total->fork);
		total->fork = 0;
	}
	if (i == 1)
	{
		write(2, "An error occured\n", 20);
	}
	return (i);
}

int main(int ac, char **av)
{
	t_total total;

	if (!(ac == 5 || ac == 6))
		return (0);
	if (make_total(&total, av))
		return (free_total(&total, 1));
	if (make_threads(&total))
		return (free_total(&total, 1));
	return (free_total(&total, 0));
}