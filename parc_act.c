/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_act.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:11:53 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/10/17 22:54:09 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_data *data)
{
	pthread_mutex_lock(data->philo->l_fork)
	message(TAKE_FORK, data);
	pthread_mutex_lock(data->philo->r_fork)
	message(TAKE_FORK, data);
}

void	drop_forks(t_data *data)
{
	pthread_mutex_unlock(data->philo->l_fork);
	pthread_mutex_unlock(data->philo->r_fork);
	message(SLEEP, data);
	my_sleep(data->philop>data->sleep_time);
}

void	eat(t_data *data)
{
	take_forks(t_data *data)
	pthread_mutex_lock(&data->lock);
	data->philo->eat_cnt = 1;
	data->philo->dead = get_time() + data->philo->data->die_tm;
	message(EAT, data);
	data->philo->eat_cnt++;
	my_sleep(data->philo->data->eat_tm);
	data->philo->eat_cnt = 0;
	thread_mutex_lock(&data->lock);
	drop_forks(data);
}

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
	return (1);
}
