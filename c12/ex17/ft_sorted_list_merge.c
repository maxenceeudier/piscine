/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:29:55 by meudier           #+#    #+#             */
/*   Updated: 2022/03/31 16:39:18 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*list;

	list = *begin_list1;
	if (!list)
		*begin_list1 = begin_list2;
	while (list->next)
		list = list->next;
	list->next = begin_list2;
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

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1, (cmp));
}
