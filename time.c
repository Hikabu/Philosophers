/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:28:07 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/10/30 13:13:19 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time (void)
{
	struct	timeval			start;
	static 	long long		fix_first_sec;
	static	int				count;

	if (gettimeofday(&start, NULL))
		return (error("FAIL\n", NULL));
	// printf("sec: %ld\n", start.tv_sec);
	// printf("usec: %d\n", start.tv_usec);
	if (count == 0)
	{
		fix_first_sec = (start.tv_sec * 1000 + start.tv_usec / 1000);
		count = 1;
	}
	return ((start.tv_sec * 1000) + (start.tv_usec / 1000) - fix_first_sec); // milisecund
}

void	mysleep(useconds_t time)
{
	long long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(50);
}
void	*routine(void *info)
{
	t_philo	*philo;

	philo = (t_philo *)info;
	if (pthread_create(&philo->philosof, NULL, one_more, (void *)philo))
		return ((void *)(1));
	while (philo->data->dead == 0)
	{	
		eat(philo);
		message(THINK, philo);
	}
	if (pthread_join(philo->philosof, NULL))
		return((void *)(1));
	if (philo->data->nbr_philo == 0)
	{
		pthread_join(philo->data->thread_id[0], NULL);
		while (philo->data->dead == 0)
			mysleep(0);
		ft_destroy(philo->data);
		return (0);
	}
	return (NULL);
}

void	*stalker(void *infa)
{
	t_philo	*philo;

	philo = (t_philo *)infa;
	pthread_mutex_lock(&philo->data->print);
	printf("data val: %d", philo->data->dead);
	pthread_mutex_unlock(&philo->data->print);
	while (philo->data->dead == 0)
	{
		pthread_mutex_lock(&philo->f_own_lock);
		if (philo->data->full >= philo->data->nbr_philo)
		{
			printf("address is: %lx", philo->data->die_tm);
			philo->data->die_tm = 1;
		}
		pthread_mutex_unlock(&philo->f_own_lock);
	}
	return (NULL);
}
