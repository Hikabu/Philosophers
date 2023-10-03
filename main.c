/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:36:24 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/10/03 17:40:05 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mails = 0;


void *routine(void *sofer)
{
	t_philo	*philo;
	
	philo = (t_philo *)sofer;
	for (int i = 0; i < 100; i++){
		pthread_mutex_lock(&philo->mutex);
		mails++;
		pthread_mutex_unlock(&philo->mutex);
	}
	printf("Im in thread : %d\n", mails);
	// sleep(3);
	// printf("the second : %d\n", mails);
	return (NULL);
}
int main(int ac, char **av)
{
	// pthread_t philo[5];
	t_philo	philos;
	// int	i;
	
	philos.nbr = 0;
	pthread_mutex_init(&philos->mutex, NULL);
	// i = 0;
	if (ac == 1 || ac == 2)
	{
		if (pars(av, &philos) == 1)
			write(2, "Error, jan\n", 11);
	}
	if (ac == 6)
	{
		
	}
	
	// else
	// 	write(2, "Too much, jan\n", 14);
	// for_time();
	// whatuint();
	// problem();
	// pthread_create(&philo2, NULL, routine, NULL);
	// pthread_join(philo2, NULL);
	pthread_mutex_destroy(&mutex);
	// printf("number of mails : %d\n", mails);
	return (0);
}
