/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:19:26 by meudier           #+#    #+#             */
/*   Updated: 2022/03/16 11:29:40 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	if (nb % 2 == 0 && nb != 2)
		return (0);
	if (nb == 3 || nb == 2)
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
/*
#include <limits.h>
#include <stdio.h>

int main(){
	int a = ft_is_prime(INT_MAX);
	int b = ft_is_prime(INT_MAX);
	int c = ft_is_prime(INT_MAX);
	printf("%d\n%d\n%d",a,b,c);
	return (0);
}*/
