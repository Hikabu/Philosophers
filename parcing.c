/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:11:53 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/10/05 16:47:23 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	erro()
{
	printf("error with argument\n");
}

int pars(char **av, t_philo *philo)
{
	int	i;
	(void)philo;
	i = 0;
	printf ("what is av: %s\n", av[1]);
	if (ft_isalpha(av[1][0]))
	{
		write(2, "no alfas ", 9);
		return (1);
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
