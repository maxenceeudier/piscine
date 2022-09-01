/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_and_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:36:46 by meudier           #+#    #+#             */
/*   Updated: 2022/03/30 15:36:49 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_error(void)
{
	write (2, "map error\n", 10);
	return (0);
}

void	ft_print_big(char **big)
{
	int	i;

	i = 0;
	while (*(big + i))
	{
		write(1, *(big + i), ft_strlen(*(big + i)));
		write (1, "\n", 1);
		i++;
	}
}

void	ft_free(char **mini, char **big, t_data *data)
{
	if (mini)
		free(mini);
	if (big)
		free(big);
	if (data)
		free(data);
}

void	ft_init(char ***mini, char ***big, t_data **data)
{
	*mini = NULL;
	*big = NULL;
	*data = NULL;
}

void	init_i_and_av(int ac, int *i, char ***av)
{
	if (ac == 1)
	{
		*i = 0;
		*(*(av)) = NULL;
	}
	else
		*i = 1;
}
