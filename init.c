/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 23:25:11 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/10/21 00:55:27 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_forks(t_data *data)
{
	int	i;
	
	i = -1;
	while (++i < data->nbr_philo)
		pthread_mutex_init(&data->fork[i], NULL);
	i = 0;
	data->philo[0].r_fork = &data->fork[0];
	data->philo[0].l_fork = &data->fork[data->nbr_philo - 1]; //circle
	i = 1;
	while (i < data->nbr_philo)
	{
		data->philo[i].r_fork = &data->fork[i];
		data->philo[i].l_fork = &data->fork[i - 1];
		i++;
	}
}

int	init_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philo)
	{
		data->philo[i].data = data;
		data->philo[i].die_tm = data->die_tm;
		data->philo[i].eat_tm = data->eat_tm;
		data->philo[i].sleep_tm = data->sleep_tm;
		data->philo[i].eating = 0;
		data->philo[i].eat_cnt = 0;
		data->philo[i].id = i + 1;
		data->thread_id = malloc(sizeof(pthread_t) * data->nbr_philo);
		if (!data->thread_id)
			return (error(MALLOC, data));
		data->thread_id = malloc(sizeof(pthread_t) * data->nbr_philo);
		// if (!data->thread_id)
		// 	return (message(MALLOC, data));
		pthread_mutex_init(&data->philo[i].f_own_lock, NULL);
		i++;
	}
	return (0);
}

int	init_1(t_data *data, char **av)
{
	int		arg;
	long	chislo;

	arg = 0;
	// data->thread_id = 0;
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
	data->dead = 0;
	init_philo(data);
	create_forks(data);
	return (0);
}

void	*one_more(void *info)
{
	t_philo	*philo;

	philo = (t_philo *)info;
	while (philo->data->die_tm == 0)
	{
		pthread_mutex_lock(&philo->f_own_lock);
		if (get_time() >= philo->die_tm && philo->eating == 0)
			message(DEAD, philo);
		if (philo->eat_cnt == philo->data->nbr_meal)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->full++;
			philo->eat_cnt++;
			pthread_mutex_unlock(&philo->data->lock);
		}
	}
	pthread_mutex_unlock(&philo->f_own_lock);
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
			return (error(TH_CREATE, data));
	}
	i = -1;
	while (++i < data->nbr_philo)
	{
		if (pthread_create(&data->thread_id[i], NULL, routine, &data->philo[i]))
			return (error(TH_CREATE, data));
		mysleep(1);
	}
	i = -1;
	while (++i < data->nbr_philo)
	{
		if(pthread_join(data->thread_id[i], NULL))
			return (error(TH_JOIN, data));
	}
	return (0);
}
