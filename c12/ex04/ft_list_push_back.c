/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:01:35 by meudier           #+#    #+#             */
/*   Updated: 2022/03/30 22:16:25 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new;
	t_list	*last;

	last = *begin_list;
	new = ft_create_elem(data);
	if (!new)
		return ;
	if (!last)
		*begin_list = new;
	while (last->next)
		last = last->next;
	last->next = new;
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

	begin = &elem1;
	elem1.next = &elem2;
	elem1.data = "coucou";
	elem2.data = "mec";
	elem2.next = 0;

	ft_list_push_back(&begin, "hey hey");

	while (begin)
	{
		printf("%s\n",(char*)begin->data);
		begin = begin->next;
	}
}*/
