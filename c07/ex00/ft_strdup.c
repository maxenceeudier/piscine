/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:47:40 by meudier           #+#    #+#             */
/*   Updated: 2022/03/18 14:33:24 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(sizeof(*src) * (ft_strlen(src) + 1));
	if (!dup)
		return (0);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}
/*
#include <stdio.h>

int main(){
	char *str;
	str = "salutnwjnwknskwkswsmkwmskwmskwmnjwnksnwknskwnskwnsssssseew";
	char *rslt = ft_strdup(str);
	printf("%s",rslt);
}*/
