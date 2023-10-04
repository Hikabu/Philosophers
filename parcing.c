/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:11:53 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/10/04 00:18:08 by valeriafedo      ###   ########.fr       */
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

	i = 0;
	printf ("what is av: %s\n", av[1]);
	if (ft_isalpha(av[1][0]))
	{
		write(2, "no alfas ", 9);
		return (1);
	}
	if (!filo_nbr(av[1], philo))
	{
		write(2, "error with nbr of philosofers\n", 31);
		return (1);
	}
	else
	{
		philo->philosof = malloc(sizeof(pthread_t) * philo->nbr);
		while (i < philo->nbr)
		{
			i++;
			if (pthread_create(philo->philosof + i, NULL, routine, &philo) != 0)
			{
				write(2, "Eror with creating thread\n", 26);
				return (1);
			}
			pthread_mutex_init(&philo->fork, NULL);
			if (pthread_join(philo->philosof[i], NULL) != 0)
				return (2);
		}
		return (0);
	}
}
