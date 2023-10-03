/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:56:05 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/09/30 10:58:10 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atol(const char *str)
{
	long long	count;
	long long	i;
	long long	otr;

	count = 0;
	i = 0;
	otr = 1;
	while (str[count] == '\n' || str[count] == '\t' || str[count] == '\f'
		|| str[count] == '\r' || str[count] == '\v' || str[count] == ' ')
		count++;
	if (str[count] == '-')
		otr = -1;
	if (str[count] == '-' || str[count] == '+')
		count++;
	while (str[count] >= 48 && str[count] <= 57)
	{
		i = i * 10 + str[count] - 48;
		count++;
	}
	return (otr * i);
}
