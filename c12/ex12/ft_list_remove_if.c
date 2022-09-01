/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:26:35 by meudier           #+#    #+#             */
/*   Updated: 2022/03/31 15:07:03 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list	*prev;
	t_list	*list;
	t_list	*current;

	prev = NULL;
	list = *begin_list;
	while (list)
	{
		if (!((*cmp)(list->data, data_ref)))
		{
			if (!prev)
				*begin_list = list->next;
			else
				prev->next = list->next;
			current = list;
			list = list->next;
			(*free_fct)(current->data);
			free(current);
		}
		else
		{
			prev = list;
			list = list->next;
		}
	}
}
