/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:51:40 by vfedorov          #+#    #+#             */
/*   Updated: 2023/09/30 10:38:51 by valeriafedo      ###   ########.fr       */
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
    int nbr;
}		t_philo;

void	for_time(); // for delete
void	whatuint(); // delete
void	problem(); // delete
int		pars(char **av, t_philo *philo);
void	*routine();
#endif
