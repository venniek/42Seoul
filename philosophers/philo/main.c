/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:11:09 by naykim            #+#    #+#             */
/*   Updated: 2021/11/16 18:11:09 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	free_and_end(t_total *total, int i)
{
	if (total->fork)
	{
		free(total->fork);
		total->fork = 0;
	}
	if (i == 1)
		write(2, "An error occured\n", 18);
	return (i);
}

int	main(int ac, char **av)
{
	t_total	total;

	if (!(ac == 5 || ac == 6))
	{
		write(2, "An error occured\n", 18);
		return (1);
	}
	memset(&total, 0, sizeof(t_total));
	if (make_total(&total, av))
		return (free_and_end(&total, 1));
	if (make_threads(&total))
		return (free_and_end(&total, 1));
	return (free_and_end(&total, 0));
}
