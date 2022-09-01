/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:08:27 by meudier           #+#    #+#             */
/*   Updated: 2022/03/31 15:13:48 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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
