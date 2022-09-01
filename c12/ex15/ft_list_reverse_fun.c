/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:17:18 by meudier           #+#    #+#             */
/*   Updated: 2022/03/31 16:02:56 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

void	ft_list_reverse_fun(t_list **begin_list)
{
	t_list	*current;
	t_list	*next;
	t_list	*prev;

	prev = NULL;
	current = *begin_list;
	if (!*begin_list)
		return ;
	while (current->next)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	current->next = prev;
	*begin_list = current;
}	
