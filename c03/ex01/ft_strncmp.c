/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:32:01 by meudier           #+#    #+#             */
/*   Updated: 2022/03/15 12:53:29 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (!n)
		return (0);
	while (i < n - 1 && s1[i] == s2[i])
	{
		if (s1[i] == 0)
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
#include <stdio.h>
int main(){
	char *s1;
	char *s2;

	s1 = "salut";
	s2 = "salutation";
	int rslt = ft_strncmp(s1,s2,7);
	printf("%d",rslt);
}*/
