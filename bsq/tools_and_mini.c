/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:44:52 by meudier           #+#    #+#             */
/*   Updated: 2022/03/30 14:44:55 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*str;

	i = ft_strlen(src);
	str = malloc(sizeof(char) * i);
	i = 0;
	while (*src)
	{
		str[i] = *src;
		src++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_plusplus(int *a, int *b, int *c, int *d)
{
	if (a)
		(*a)++;
	if (b)
		(*b)++;
	if (c)
		(*c)++;
	if (d)
		(*d)--;
}

int	ft_init_stuff(char **mini, int *i)
{
	int	i_bis;

	(*i) = 0;
	i_bis = 0;
	while (*(mini + (i_bis + 1)))
		i_bis++;
	return (i_bis);
}

char	**create_mini(int size)
{
	char	**mini;
	char	*mini_temp;
	int		i;

	i = 0;
	mini_temp = malloc(sizeof(char) * ((size + 1) * size + 1));
	if (!mini_temp || !size)
		return (NULL);
	while (i < (size + 1) * size)
	{	
		if ((i + 1) % (size + 1) == 0)
			mini_temp[i] = 'o';
		else
			mini_temp[i] = '.';
		i++;
	}
	mini_temp[i] = 0;
	mini = ft_split(mini_temp, "o");
	free(mini_temp);
	return (mini);
}
