/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:28:35 by meudier           #+#    #+#             */
/*   Updated: 2022/03/15 14:32:06 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	nbr;

	if (nb < 0)
		return (0);
	nbr = 1;
	i = 1;
	while (i <= nb)
	{
		nbr = i * nbr;
		i++;
	}
	return (nbr);
}
/*
#include <stdio.h>

int main(){
	int a = ft_iterative_factorial(2);
	printf("%d",a);
	return (0);
}*/
