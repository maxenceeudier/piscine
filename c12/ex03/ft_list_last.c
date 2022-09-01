/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:47:09 by meudier           #+#    #+#             */
/*   Updated: 2022/03/30 22:00:11 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}
/*
#include <stdio.h>

int main()
{
	t_list *begin;
        t_list elem1;
        t_list  elem2;
	t_list	elem3;

        begin = &elem1;
        elem1.next = &elem2;
        elem1.data = "coucou";
        elem2.data = "mec";
        elem2.next = &elem3;
	elem3.data = "last";
	elem3.next = 0;

	t_list *last;
	last = ft_list_last(begin);
	printf("%s",(char *)last->data);
}*/
