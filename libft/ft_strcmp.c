/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:51:39 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/10/20 14:01:19 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1 && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}
