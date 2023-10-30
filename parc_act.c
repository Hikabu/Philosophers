/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_act.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:11:53 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/10/30 22:42:56 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	
	pthread_mutex_lock(philo->l_fork);
	message(TAKE_FORK, philo);
	pthread_mutex_lock(philo->r_fork);
	message(TAKE_FORK, philo);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	message(SLEEP, philo);
	mysleep(philo->data->sleep_tm);
}

void	eat(t_philo *philo)
{
	printf("address is: %ld\n", philo->data->die_tm);
	take_forks(philo);
	philo->eating = 1;
	philo->die_tm = get_time() + philo->data->die_tm;
	message(EAT, philo);
	philo->eat_cnt++;
	mysleep(philo->data->eat_tm);
	philo->eating = 0;
	drop_forks(philo);
}

int pars(t_data *data, char **av)
{
	int	i;
	(void)data;
	i = 1;
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
