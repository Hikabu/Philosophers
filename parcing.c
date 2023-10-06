/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:11:53 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/10/06 18:32:17 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	erro()
{
	printf("error with argument\n");
}

int pars(t_data *data, char **av)
{
	int	i;
	(void)data;
	i = 0;
	printf ("what is av: %s\n", av[1]);
	while (av[i])
	{
		if (ft_strisnum(av[i]) == 1)
		{
			write (2, "My program need only NUMBERS\n", 29);
			return (1);
		}
	}
	// else
	// {
	// 	while (i < philo->nbr)
	// 	{
	// 		i++;
	// 		if (pthread_create(philo->philosof + i, NULL, routine, &philo) != 0)
	// 		{
	// 			write(2, "Eror with creating thread\n", 26);
	// 			return (1);
	// 		}
	// 		pthread_mutex_init(&philo->fork, NULL);
	// 		if (pthread_join(philo->philosof[i], NULL) != 0)
	// 			return (2);
	// 	}
	// 	return (0);
	// }
	return (0);
}
