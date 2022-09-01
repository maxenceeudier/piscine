/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:37:59 by meudier           #+#    #+#             */
/*   Updated: 2022/03/16 12:03:10 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	if (nb % 2 == 0 && nb != 2)
		return (0);
	if (nb == 3)
		return (1);
	i = 3;
	while (i < nb / 2 + 1)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 3)
		return (2);
	if (nb % 2 == 0)
			nb++;
	while (!ft_is_prime(nb))
		nb += 2;
	return (nb);
}
/*
#include <stdio.h>
#include <limits.h>
int main(){
	int a = ft_find_next_prime(INT_MAX);
	int b = ft_find_next_prime(INT_MAX);
	int c = ft_find_next_prime(INT_MAX);
	printf("%d\n%d\n%d",a,b,c);
	return (0);
}*/
