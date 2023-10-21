/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:36:24 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/10/20 16:32:18 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philo)
	{
		pthread_mutex_destroy(&data->fork[i]);
		pthread_mutex_destroy(&data->philo[i].f_own_lock);
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->lock);
	free(data->thread_id);
}
int	error(char *str, t_data *data)
{
	printf("%s\n", str);
	if (data)
		ft_destroy(data);
	return (1);
}
int	message(char *str, t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->data->print);
	time = get_time();
	if (ft_strcmp(DEAD, str) == 0 && philo->data->die_tm == 0)
		printf("%llu %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->print);
	return (0);
}
int main(int ac, char **av)
{
	t_data	data;
	
	// data.nado = NULL;
	if (ac == 5 || ac == 6)
	{
		if (!pars(&data, av))
			return (message(E_PAR, NULL));
		get_time();
		if (init_1(&data, av))
			return (1);
		if (action(&data))
			return (1);
		ft_destroy(&data);
	}
	return (0);
}
