/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:36:24 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/10/14 17:36:18 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philo)
	{
		pthread_mutex_destroy(&data->philo[i].f_own_lock);
	}
	pthread_mutex_destroy(&data->print);
}
int	message(char *str, t_data *data)
{
	printf("%s\n", str);
	if (data)
		ft_destroy(data);
	return (1);
}
int main(int ac, char **av)
{
	t_data	data;
	
	data.nado = NULL;
	if (ac == 5 || ac == 6)
	{
		if (!pars(&data, av))
			return (message(E_PAR, NULL));
		if (init_1(&data, av))
			return (1);
		if (action(&data))
			return (1);
	}
	else
		return (message(E_ARG, NULL));
	return (0);
}
