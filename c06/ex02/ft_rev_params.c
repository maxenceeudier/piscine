/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 08:52:23 by meudier           #+#    #+#             */
/*   Updated: 2022/03/18 08:52:26 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write (1, str++, 1);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = argc - 1;
	while (i)
	{
		ft_putstr(argv[i]);
		write (1, "\n", 1);
		i--;
	}
	return (0);
}
