/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:36:36 by meudier           #+#    #+#             */
/*   Updated: 2022/03/16 11:58:04 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	nb = nb * ft_recursive_power(nb, power - 1);
	return (nb);
}
/*
#include <stdio.h>

int main(){
	int a = ft_recursive_power(5,2);
	printf("%d",a);
	return (0);
}*/
