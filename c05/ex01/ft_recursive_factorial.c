/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:10:33 by meudier           #+#    #+#             */
/*   Updated: 2022/03/16 12:00:11 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	else
		nb = nb * ft_recursive_factorial(nb -1);
	return (nb);
}
/*
#include <stdio.h>

int main(){
	int a = ft_recursive_factorial(5);
	printf("%d",a);
	return (0);
}*/
