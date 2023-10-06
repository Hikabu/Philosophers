/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:51:40 by vfedorov          #+#    #+#             */
/*   Updated: 2023/10/06 18:23:35 by vfedorov         ###   ########.fr       */
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
	long			die;
	long			eat;
	long			sleep;
	long			optin;
	pthread_t		*philosof;
	pthread_mutex_t	*fork;
} t_philo;

typedef struct s_data
{
	pthread_mutex_t fork[200];
	long			eat_tm;
	long			sleep_tm;
	long			die_tm;
	long			nbr_philo;
	long			eatphilo;
	int				nbr;
	int				id;
	pthread_mutex_t	*forks;
	t_philo			philo[200];
} t_data;

void		for_time(); // for delete
void		whatuint(); // delete
void		problem(); // delete
int			pars(t_philo *philo, char **av);
long long	get_time(void);
void		*routine(void *sofer);
void		init_1(t_data *data, char **av);
int			mysleep(useconds_t time);
// int			parc (t_data *data, char **av);
void		erro();
#endif
