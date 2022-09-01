/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:53:43 by meudier           #+#    #+#             */
/*   Updated: 2022/03/22 09:27:38 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned int	n;
	unsigned int	test;

	if (nb <= 0)
		return (0);
	n = nb;
	test = 1;
	while (test * test < n)
		test++;
	if (test * test == n)
		return (test);
	else
		return (0);
}

#include <stdio.h>
#include <limits.h>
int main(){
	int a = ft_sqrt(2147483600);
	printf("%d",a);
	return (0);
}
