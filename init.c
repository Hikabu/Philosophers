/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 23:25:11 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/10/08 19:05:55 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_1(t_data *data, char **av)
{
	int		arg;
	long	chislo;

	arg = 0;
	while (av[++arg])	
	{
		if (!ft_strisnum(av[arg]))
			write(2, "error\n", 6);
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
			data->eatphilo = ft_atol(av[arg]);
}

// int	parc (t_data *data, char **av)
// {
// 	int	i;

// 	i = 0;
// 	while (av[i])
// 	{
// 		if (!ft_isalnum(av[i]))
// 			write(2, "error\n", 6);
// 		i++;
// 	}
// }
// void	init_2(t_data *data)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < data->nbr_philo)
// 	{
// 		if (pthread_create(data->philo + i, NULL, routine, &data) != 0)
// 			{
// 				write(2, "Eror with creating thread\n", 26);
// 				return (1);
// 			}
// 			pthread_mutex_init(&data->forks, NULL);
// 			if (pthread_join(data->philo[i], NULL) != 0)
// 				return (2);
// 	}
// }
