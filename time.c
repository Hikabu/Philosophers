/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:28:07 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/10/21 01:16:12 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time (void)
{
	struct	timeval			start;
	// static	long long		time;
	// static int				i;

	if (gettimeofday(&start, NULL))
		return (error("FAIL\n", NULL));
	// if (!i)
	// {
	// 	i = 1;
	// 	time = start.tv_sec * 1000LL + start.tv_usec / 1000LL;
	// }
	return ((start.tv_sec * 1000LL )+ (start.tv_usec / 1000LL));
}

void	mysleep(useconds_t time)
{
	long long	start;

	start = get_time();
	while (get_time() - start < time)
		;
}
void	*routine(void *info)
{
	t_philo	*philo;

	philo = (t_philo *)info;
	// philo->die_tm = philo->data->die_tm + get_time();
	if (pthread_create(&philo->philosof, NULL, one_more, (void *)philo))
		return ((void *)(1));
	printf("%d\n", philo->data->dead);
	while (philo->data->dead == 0)
	{
		eat(philo);
		message(THINK, philo);
	}
	if (pthread_join(philo->philosof, NULL))
		return((void *)(1));
	return (NULL);
}

void	*stalker(void *infa)
{
	t_philo	*philo;

	philo = (t_philo *)infa;
	pthread_mutex_lock(&philo->data->print);
	printf("some action and data val is %d", philo->data->dead);
	pthread_mutex_unlock(&philo->data->print);
	while (philo->die_tm == 0)
	{
		pthread_mutex_lock(&philo->f_own_lock);
		if (philo->data->full >= philo->data->nbr_philo)
			philo->data->die_tm = 1;
		pthread_mutex_unlock(&philo->f_own_lock);
	}
	return (NULL);
}
