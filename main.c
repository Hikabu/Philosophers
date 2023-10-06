/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:36:24 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/10/06 14:29:07 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	mails = 0;

// void *routine(void *sofer)
// {
// 	t_philo	*philo;
	
// 	philo = (t_philo *)sofer;
// 	for (int i = 0; i < 100; i++){
// 		pthread_mutex_lock(&philo->fork);
// 		mails++;
// 		pthread_mutex_unlock(&philo->fork);
// 	}
// 	printf("Im in thread : %d\n", mails);
// 	// sleep(3);
// 	// printf("the second : %d\n", mails);
// 	return (NULL);
// }
int main(int ac, char **av)
{
	// (void)ac;
	// (void)av;
	t_data	data;
	
	if (ac == 5 || ac == 6)
	{
		pars(&data, av);
		init_1(&data, av);
	}
	else
		return (1);
	// pthread_mutex_init(&philos.fork, NULL);
	return (0);
}
