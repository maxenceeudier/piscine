/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:20:40 by meudier           #+#    #+#             */
/*   Updated: 2022/03/22 16:41:28 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	length(int size, char **strs, char *sep)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j++])
			len++;
		j = 0;
		if (i != size - 1)
		{
			while (sep && sep[j++])
				len++;
		}
		i++;
	}
	return (len);
}

char	*error(void)
{
	char	*strerror;

	strerror = malloc(sizeof(char));
	*strerror = '\0';
	return (strerror);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*strjoin;
	int		i;
	int		j;
	int		k;

	if (size <= 0 || !strs)
		strjoin = error();
	else
	{
		strjoin = malloc(sizeof(**strs) * length(size, strs, sep) + 1);
		i = -1;
		k = 0;
		while (++i < size)
		{
			j = 0;
			while (strs[i][j])
				strjoin[k++] = strs[i][j++];
			j = 0;
			if (i < size -1 && sep)
				while (sep[j])
					strjoin[k++] = sep[j++];
		}
		strjoin[k] = 0;
	}
	return (strjoin);
}
/*
#include <stdio.h>
   int main(){
   char *strs[4]= {"salut","mec","ca va","?"};
   char *strjoin = ft_strjoin(0, strs, "...");
   printf("%s\n",strjoin);
   }*/