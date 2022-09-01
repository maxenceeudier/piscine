/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:06:49 by meudier           #+#    #+#             */
/*   Updated: 2022/03/24 17:24:03 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	j;
	int	direction;

	direction = 0;
	i = 0;
	while (i < length - 1)
	{	
		j = i + 1;
		if ((*f)(tab[i], tab[j]) > 0 && !direction)
			direction = -1;
		else if ((*f)(tab[i], tab[j]) < 0 && !direction)
			direction = 1;
		else if ((*f)(tab[i], tab[j]) > 0 && direction == 1)
			return (0);
		else if ((*f)(tab[i], tab[j]) < 0 && direction == -1)
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
int	ft_intcmp(int a, int b)
{
	return (a - b);
}

int main(){
	int tab[] = {6,5,4,3,2,1};
	int a = ft_is_sort(tab, 6, &ft_intcmp);
	printf("%i",a);
}*/