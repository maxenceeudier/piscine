/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:07:22 by meudier           #+#    #+#             */
/*   Updated: 2022/03/30 14:15:25 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	you_win(char **big, char **mini, t_data *data)
{
	ft_solver(big, mini, data);
	ft_print_big(big);
}

void	find_the_square(t_data **data, char **big, char **mini)
{
	while ((*data)->born_sup - (*data)->born_inf >= 0)
	{
		mini = create_mini((*data)->num_max);
		if (ft_solver(big, mini, *data))
		{
			(*data)->born_inf = (*data)->num_max;
			(*data)->num_max += ((*data)->born_sup - (*data)->born_inf) / 2;
			if ((*data)->born_sup - (*data)->born_inf == 1
				|| (*data)->born_sup - (*data)->born_inf == 0)
			{
				you_win(big, mini, *data);
				break ;
			}
		}
		else
		{
			(*data)->born_sup = (*data)->num_max;
			if ((*data)->born_sup - (*data)->born_inf == 1
				|| ((*data)->num_max == 1))
				(*data)->num_max -= 1;
			else
				(*data)->num_max -= ((*data)->born_sup - (*data)->born_inf) / 2;
			free(mini);
		}
	}
}

int	main(int ac, char **av)
{
	char	**big;
	char	**mini;
	t_data	*data;
	int		i;

	init_i_and_av(ac, &i, &av);
	while (i < ac)
	{
		ft_init(&mini, &big, &data);
		if (!get_data_and_map(*(av + i), &big, &data))
			ft_error();
		else
		{
			find_the_square(&data, big, mini);
		}
		ft_free(mini, big, data);
		i++;
	}
	return (0);
}
