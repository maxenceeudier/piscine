/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:14:49 by meudier           #+#    #+#             */
/*   Updated: 2022/03/15 18:32:07 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (++i < power)
		nbr = nbr * nb;
	return (nbr);
}
/*
#include <stdio.h>

int main(){
	int a = ft_iterative_power(10,3);
	printf("%d",a);
	return (0);
}*/
