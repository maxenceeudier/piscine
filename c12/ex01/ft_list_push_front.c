/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:41:24 by meudier           #+#    #+#             */
/*   Updated: 2022/03/28 11:53:14 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>
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
/*
#include <stdio.h>

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
	t_list elem1;
	t_list	elem2;

	begin = NULL;
	elem1.next = &elem2;
	elem1.data = "coucou";
	elem2.data = "mec";
	elem2.next = 0;
	
	ft_list_push_front(&begin, "hey hey");

	while (begin)
	{
		printf("%s\n",(char*)begin->data);
		begin = begin->next;
	}
}*/
