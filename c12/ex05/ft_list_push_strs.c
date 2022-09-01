/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:19:31 by meudier           #+#    #+#             */
/*   Updated: 2022/03/30 22:42:49 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_elem;

	new_elem = ft_create_elem(data);
	if (!new_elem)
		return ;
	if (!*begin_list)
	{
		*begin_list = new_elem;
		return ;
	}
	new_elem->next = *begin_list;
	*begin_list = new_elem;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*begin;

	i = 0;
	while (i < size)
	{
		ft_list_push_front(&begin, strs[i]);
		i++;
	}
	return (begin);
}
/*
#include <stdio.h>
#include <string.h>
char	**ft_split(char *str, char *charset);

t_list	*ft_create_elem(void *data)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->data = data;
	new_elem->next = NULL;
	return (new_elem);
}

int	main(){
	t_list *begin;
	char	*str;
	str = "salut mec ca va ou quoi ?";
	
	begin = ft_list_push_strs(7, ft_split(str, " "));

	while (begin->next)
	{
		printf("%s\n",(char*)begin->data);
		begin = begin->next;
	}
}
*/
