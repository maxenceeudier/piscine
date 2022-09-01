/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:34:42 by meudier           #+#    #+#             */
/*   Updated: 2022/03/21 21:09:47 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*tab;
	int		size;
	int		i;

	size = max - min;
	tab = malloc(sizeof(*tab) * (size + 1));
	if (!tab || min >= max)
		return (0);
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
/*
int main(){
	int *tab = ft_range(5,89);
	while (*tab)
	{
		printf("%d, ",*tab);
		tab++;
	}
 	return (0);	
}*/
