/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:39:05 by meudier           #+#    #+#             */
/*   Updated: 2022/03/23 11:11:18 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av);

void	ft_putnbr(int nbr)
{
	char	temp;
	long	n;

	n = nbr;
	if (n < 0)
	{
		write (1, "-", 1);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	temp = n % 10 + '0';
	write (1, &temp, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write (1, str++, 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		write (1, "\n", 1);
		ft_putnbr(par[i].size);
		write (1, "\n", 1);
		ft_putstr(par[i].copy);
		write (1, "\n", 1);
		i++;
	}
}
/*
int main(int ac, char **av)
{
	t_stock_str	*stock;

	stock = ft_strs_to_tab(ac, av);
	ft_show_tab(stock);
	return(0);
}*/
