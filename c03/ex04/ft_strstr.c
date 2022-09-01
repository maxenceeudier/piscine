/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:41:10 by meudier           #+#    #+#             */
/*   Updated: 2022/03/14 11:38:28 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>  

int	is_to_find(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i] == str[i])
	{
		if (to_find[i] == 0)
			return (1);
		i++;
	}
	if (to_find[i])
		return (0);
	else
		return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (!*to_find)
		return (str);
	while (*str)
	{
		if (is_to_find(str, to_find))
			return (str);
		str++;
	}
	return (NULL);
}
/*
#include <unistd.h>
int main(){
	char *str;
	char *to_find;
	str = "hellomadfcdcdrni";
	to_find = "rni";
	char *rslt = ft_strstr(str, to_find);
	write (1, rslt,1);
	return 0;
}*/
