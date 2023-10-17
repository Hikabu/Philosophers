/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:28:07 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/10/17 22:54:12 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time()
{
	static struct	timeval	start;
	static long long		time;
	static int				i;

	gettimeofday(&start, NULL);
	if (!i)
	{
		i = 1;
		time = start.tv_sec * 1000LL + start.tv_usec / 1000LL;
	}
	return ((start.tv_sec * 1000LL) + (start.tv_usec / 1000LL) - time);
}

int	mysleep(useconds_t time)
{
	long long	start;
	
	start = get_time();
	while (get_time() - start < time)
		;
	return (0);
}
void	*routine(void *info)
{
	t_data	*data;

	data = info;
	if (pthread_create(&data->philo->philosof, NULL, one_more, &data))
		return ((void *)(1));
	while (data->philo->data->dead == 0)
	{
		eat(data);
		message(THINK, data);
	}
	if (pthread_join(data->philo->philosof, NULL))
		return((void *)(1));
	return (NULL);
}

void	*stalker(void *infa)
{
	t_data	*data;

	data = infa;
	pthread_mutex_lock(&data->philo->data->print);
	printf("some action and data val is %d", data->philo->data->dead);
	pthread_mutex_unlock(&data->philo->data->print);
	while (data->philo->data->dead == 0)
	{
		pthread_mutex_lock(&data->lock);
		if (data->philo->data->full >= data->philo->data->nbr_philo)
			data->philo->data->dead = 1;
		pthread_mutex_unlock(&data->lock);
	}
	return (NULL);
}
