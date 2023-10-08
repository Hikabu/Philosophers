/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:11:53 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/10/08 21:44:43 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int pars(t_data *data, char **av)
{
	int	i;
	(void)data;
	i = 1;
	printf ("what is av: %s\n", av[1]);
	while (av[i])
	{
		if (ft_atol(av[1]) > 200)
			return (0);
		if (!ft_strisnum(av[i]))
			return (0);
		i++;
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
	return (1);
}
