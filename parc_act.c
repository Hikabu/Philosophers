/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_act.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:11:53 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/10/24 00:12:35 by valeriafedo      ###   ########.fr       */
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
	
	take_forks(philo);
	pthread_mutex_lock(&philo->f_own_lock);
	philo->eating = 1;
	philo->die_tm = get_time() + philo->data->die_tm;
	message(EAT, philo);
	philo->eat_cnt++;
	mysleep(philo->data->eat_tm);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->f_own_lock);
	drop_forks(philo);
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
