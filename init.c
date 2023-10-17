/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 23:25:11 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/10/17 22:06:30 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philo)
	{
		data->philo[i].data = data;
		data->philo[i].dead = data->die_tm;
		data->philo[i].eat_cnt = 0;
		data->philo[i].id = i + 1;
		data->philo[i].status = 0;
		pthread_mutex_init(&data->philo[i].f_own_lock, NULL);
		i++;
	}
}

int	init_1(t_data *data, char **av)
{
	int		arg;
	long	chislo;

	arg = 0;
	while (av[++arg])	
	{
		chislo = ft_atol(av[arg]);
		if (arg == 1)
			data->nbr_philo = chislo;
		else if (arg == 2)
			data->die_tm = chislo;
		else if (arg == 3)
			data->eat_tm = chislo;
		else if (arg == 4)
			data->sleep_tm = chislo;
	}
	if (arg == 5)
		data->nbr_meal = ft_atol(av[arg]);
	init_philo(data);
	create_forks(data);
	return (0);
}


void	create_forks(t_data *data)
{
	int	i;
	
	i = -1;
	while (++i < data->nbr_philo)
		if (pthread_mutex_init(&data->fork[i], NULL))
	data->philo[0].r_fork = &data->fork[0];
	data->philo[0].l_fork = &data->fork[data->nbr_philo - 1]; //circle
	i = 0;
	while (++i < data->nbr_philo)
	{
		data->philo[i].r_fork = &data->fork[i];
		data->philo[i].l_fork = &data->fork[i - 1];
		i++;
	}
}

void	*one_more(void *info)
{
	t_data	*data;

	data = info;
	while (data->philo->data->dead == 0)
	{
		pthread_mutex_lock(&data->lock);
		if (get_time() >= data->philo->dead && data->philo->eat_cnt == 0)
			message(DEAD, data);
		if (data->philo->eat_cnt == data->philo->data->nbr_meal)
		{
			pthread_mutex_lock(&data->philo->data->lock);
			data->philo->data->full++;
			data->philo->eat_cnt++;
			pthread_mutex_unlock(&data->philo->data->lock);
		}
	}
	pthread_mutex_unlock(&data->lock);
	return (NULL);
}

int	action(t_data *data)
{
	int			i;
	pthread_t	arg_six;

	data->start_time = get_time();
	if (data->nbr_meal > 0)
	{
		if (pthread_create(&arg_six, NULL, stalker, &data->philo[0]))
			return (message(TH_CREATE, data));
	}
	i = -1;
	while (++i < data->nbr_philo)
	{
		if (pthread_create(&data->thread_id[i], NULL, routine, &data->philo[i]))
			return (message(TH_CREATE, data));
		mysleep(1);
	}
	i = -1;
	while (++i < data->nbr_philo)
	{
		if(pthread_join(data->thread_id[i], NULL))
			return (message(TH_JOIN, data));
	}
	return (0);
}
