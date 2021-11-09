#include "philosophers.h"

int main(int ac, char **av)
{
	t_total total;

	if (!(ac == 5 || ac == 6))
		return (0);
	if (make_total(&total, av))
	return (1);
	if (make_threads(&total))
		return (1);
	return 0;
}