/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:15:23 by meudier           #+#    #+#             */
/*   Updated: 2022/03/14 20:35:55 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	len;
	unsigned int	i;

	len_dest = ft_strlen(dest);
	len = len_dest + ft_strlen(src);
	i = 0;
	while (src[i] && len_dest + i < size - 1 && size != 0)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	if (size < len_dest)
		return (size + ft_strlen(src));
	else
		return (len);
}
/*
#include <stdio.h>
int main(){
	char dest[100]="slt ";
	char *src;
	src = "Anastasiia";
	unsigned int rslt = ft_strlcat(dest, src,0);
	printf("len : %d\ndest : %s",rslt,dest);

}*/
