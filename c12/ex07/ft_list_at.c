/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:36:13 by meudier           #+#    #+#             */
/*   Updated: 2022/03/31 09:40:31 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	pos;
	t_list			*current;

	if (!nbr)
		return (NULL);
	curent = begin_list;
	pos = 1;
	while (current)
	{
		if (pos == nbr)
			return (curent);
		pos++;
		current = current->next;
	}
	return (NULL);
}
