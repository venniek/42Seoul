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

int	free_total(t_total *total, int i)
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

int	error_manage(int i)
{
	write(2, "Argument Error", 14);
	return (i);
}

int	main(int ac, char **av)
{
	t_total	total;

	if (!(ac == 5 || ac == 6))
		return (error_manage(1));
	if (make_total(&total, av))
		return (free_total(&total, 1));
	if (make_threads(&total))
		return (free_total(&total, 1));
	return (free_total(&total, 0));
}
