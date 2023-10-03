/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:51:40 by vfedorov          #+#    #+#             */
/*   Updated: 2023/10/03 17:37:18 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdint.h>
#include <pthread.h>
#include "./libft/libft.h"

// struct timeval
//{
//		time_t		tv_sec;         /* seconds */
//     suseconds_t tv_usec;        /* microseconds */
//}

typedef struct s_philo
{
	int				nbr;
	int				die;
	int				eat;
	int				sleep;
	int				optin;
	pthread_t		*philosof;
	pthread_mutex_t	mutex;
} t_philo;

void	for_time(); // for delete
void	whatuint(); // delete
void	problem(); // delete
int		pars(char **av, t_philo *philo);
void	*routine(void *sofer);
#endif
