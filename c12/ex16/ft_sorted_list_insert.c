/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:04:39 by meudier           #+#    #+#             */
/*   Updated: 2022/03/31 16:27:53 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>
#include <stdlib.h>

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

void	ft_swap_list(t_list **begin, t_list **current,
		t_list **prev, t_list **next)
{
	if (!prev)
	{
		(*current)->next = (*next)->next;
		(*next)->next = *current;
		*begin = *next;
	}
	else
	{
		(*prev)->next = (*current)->next;
		(*current)->next = (*next)->next;
		(*next)->next = *current;
	}
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*prev;
	t_list	*list;

	prev = NULL;
	list = *begin_list;
	while (list)
	{
		if ((*cmp)(list->data, list->next->data) > 0)
		{	
			ft_swap_list(begin_list, &list, &prev, &list->next);
			list = *begin_list;
		}
		else
		{
			prev = list;
			list = list->next;
		}
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	ft_list_push_front(begin_list, data);
	ft_list_sort(begin_list, (cmp));
}	
