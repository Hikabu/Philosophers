/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:28:07 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/10/04 21:19:05 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// struct timeval()
// {
// 	time_t		tv_sec;  seconds from lanuary 1, 1970
// 	suseconds_t	tv_usec;  microseconds sec * 10000
// }

// int gettimeofday(struct timeval tv, struct timezone *tz);

// void	for_time()
// {
//     struct timeval time;
    
//     if (gettimeofday(&time, NULL)) // no need in timezone
//         return ;
//     printf("%ld new year seconds\n", time.tv_sec);
//     printf("%d  new yerar microseconds\n", time.tv_usec);
// 	printf("%ld years from 1970\n", time.tv_sec /60/60/24/365);
    
// }
long long	get_time()
{
	struct			timeval	tm;
	static struct	timeval	start;

	if (i == 0)
	{
		gettimeofday(&start, NULL);
		i = 1;
	}
	if (gettimeofday(&tm, NULL))
		return (0);
	tm.tv_sec = tm.tv_sec - start.tv_sec;
	return ((tm.tv_sec * 1000LL) + (tm.tv_usec / 1000LL));
}
void	erro()
{
	printf("error with argument\n");
}

int	mysleep(useconds_t time)
{
	long long	start;
	
	start = get_time();
	while (get_time() - start > time)
		usleep(time / 10);
	return (0);
}

void	problem()
{
	struct timeval	start_time;
	struct timeval	end_time;
	long			zapros;
	long			actual;
	
	zapros = 100 * 1000;
	gettimeofday(&start_time, NULL);
	mysleep(zapros);
	gettimeofday(&end_time, NULL);
	actual = ((end_time.tv_sec - start_time.tv_sec) * 1000000) + (end_time.tv_usec - start_time.tv_usec);
	printf("our request: %ld\n", zapros);
	printf("actial time: %ld\n", actual);
}
