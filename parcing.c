/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:11:53 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/09/30 11:19:01 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int filo_nbr(char *str, t_philo *philo)
{
    philo->nbr = 0;
    philo->nbr = ft_atol(str);
	printf("after atoi str= %d\n", philo->nbr);
    return (philo->nbr);
}
int pars(char **av, t_philo *philo)
{
	int	i;
	pthread_t *philosof;

	i = 0;
	printf ("what is av: %s\n", av[1]);
	if (ft_isalpha(av[1][0]))
	{
		write(2, "no alfas ", 9);
		return (1);
	}
	if (!filo_nbr(av[1], philo))
	{
		write(2, "error with nbr of philosofers\n", 31);
		return (1);
	}
	else
	{
		philosof = malloc(sizeof(pthread_t) * philo->nbr);
		while (i < philo->nbr)
		{
			i++;
			if (pthread_create(philosof + i, NULL, routine, NULL) != 0)
			{
				write(2, "Eror with creating thread\n", 26);
				return (1);
			}
			if (pthread_join(philosof[i], NULL) != 0)
				return (2);
		}
		return (0);
	}
}
