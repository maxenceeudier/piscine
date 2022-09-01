/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:19:22 by meudier           #+#    #+#             */
/*   Updated: 2022/03/28 12:26:07 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}
/*
#include <stdio.h>

int     main(){
        t_list *begin;
        t_list elem1;
        t_list  elem2;
	t_list	elem3;

        begin = &elem1;
        elem1.next = &elem2;
        elem1.data = "coucou";
        elem2.data = "mec";
        elem2.next = &elem3;
	elem3.next = 0;

        printf("%d", ft_list_size(begin));
}*/
