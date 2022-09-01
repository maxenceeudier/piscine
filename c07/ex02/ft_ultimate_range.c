/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:09:55 by meudier           #+#    #+#             */
/*   Updated: 2022/03/22 12:38:33 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	size = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(sizeof(**range) * (size + 1));
	if (!*range)
		return (-1);
	i = 0;
	while (min < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	(*range)[i] = 0;
	return (size);
}
/*
#include <stdio.h>
   int main(){
   int *tab;
   int a = ft_ultimate_range(&tab, -35, 20);
   int i = 0;

   while (i < 55)
   {                       
   printf("%d, ",tab[i]);
   i++;
   }
   printf("\n%d",a);
   return (0);     
   }*/
