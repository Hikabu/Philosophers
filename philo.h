/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:51:40 by vfedorov          #+#    #+#             */
/*   Updated: 2023/10/16 21:32:57 by valeriafedo      ###   ########.fr       */
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

# define E_ARG "Wrong arguments"
# define E_PAR "Not good parcing"
# define TH_CREATE "Error with thread creating"
# define TH_JOIN "Error with thread joining"
# define FORK "has taken a fork"
# define DEAD "died"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"

// struct timeval
//{
//		time_t		tv_sec;         /* seconds */
//     suseconds_t tv_usec;        /* microseconds */
//}

typedef struct s_philo
{
	struct s_data	*data;
	long			dead;
	long			eat_cnt;
	long			sleep;
	long			status;
	// pthread_t		thread_id;
	int				id;
	pthread_t		philosof; //dont need to use(only for pthread)
	pthread_mutex_t	f_own_lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
} t_philo;

typedef struct s_data
{
	pthread_mutex_t fork[200];
	long			eat_tm;
	pthread_t		*thread_id;
	long			sleep_tm;
	long			die_tm;
	long			nbr_philo;
	long			nbr_meal;
	long long		start_time;
	int				nbr;
	int				id;
	int				dead;
	int				full;
	char			*nado;
	pthread_mutex_t print;
	pthread_mutex_t lock;
	t_philo			philo[200];
} t_data;

// void		for_time(); // for delete
// void		whatuint(); // delete
// void		problem(); // delete
int			pars(t_data *data, char **av);
long long	get_time(void);
void		init_philo(t_data *data);
int			init_1(t_data *data, char **av);
int			mysleep(useconds_t time);
// int			parc (t_data *data, char **av);
void		erro();
void		create_forks(t_data *data);
int			message(char *str, t_data *data);
int			action(t_data *data);
void		*one_more(void *info);
void		*routine(void *sofer);
void		*stalker(void *infa);
#endif
