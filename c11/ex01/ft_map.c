/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:29:29 by meudier           #+#    #+#             */
/*   Updated: 2022/03/24 16:35:38 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*rslt;

	i = 0;
	rslt = malloc(sizeof(int) * (length + 1));
	if (!rslt)
		return (0);
	while (i < length)
	{
		rslt[i] = (*f)(tab[i]);
		i++;
	}
	rslt[i] = 0;
	return (rslt);
}
/*
#include <stdio.h>
int	sum(int a){
	return (a + 2);
}
int main(){
	int tab[] = {1,4,5,7,8,56,324};
	int i = 0;
	int *rslt = ft_map(tab,7,&sum);
	while (i < 7)
	{
		printf("%d\n",rslt[i++]);
	}
}*/
