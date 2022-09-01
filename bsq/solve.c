/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahlou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:56:52 by slahlou           #+#    #+#             */
/*   Updated: 2022/03/30 16:35:40 by slahlou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_mask_on(char **big, char **mini, t_data *p)
{
	int	i;
	int	e;
	int	pos_y;
	int	pos_x;
	int	i_bis;

	pos_y = p->y;
	pos_x = p->x;
	i_bis = ft_init_stuff(mini, &i);
	while (i_bis - i >= 0)
	{
		e = 0;
		pos_y = p->y;
		while (*(*(mini + i) + e))
		{	
			if ((*(*(big + pos_x) + pos_y) == p->obstacle)
				|| (*(*(big + (pos_x + (i_bis - i))) + pos_y) == p->obstacle))
				return (0);
			ft_plusplus(&pos_y, &e, 0, 0);
		}
		ft_plusplus(&pos_x, &i, 0, &i_bis);
	}
	return (1);
}

void	ft_applied_mask(char **big, char **mini, t_data *p)
{
	int	i;
	int	e;
	int	pos_y;
	int	pos_x;

	pos_y = p->y;
	pos_x = p->x;
	i = 0;
	while (*(mini + i))
	{
		pos_y = p->y;
		e = 0;
		while (*(*(mini + i) + e))
		{
			*(*(big + pos_x) + pos_y) = p->plein;
			pos_y++;
			e++;
		}
		pos_x++;
		i++;
	}
}

int	ft_linelen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i - 1);
}

int	ft_collen(char **strs)
{
	int	i;

	i = 0;
	while (*(strs + i))
		i++;
	return (i - 1);
}

int	ft_solver(char **big, char **mini, t_data *p)
{
	if (!mini)
		return (0);
	p->x = 0;
	while (*(big + (p->x + ft_collen(mini))))
	{
		p->y = 0;
		while (*(*(big + p->x) + (p->y + ft_linelen(*mini))))
		{	
			if (ft_mask_on(big, mini, p))
			{	
				if (p->born_sup - p->born_inf == 1
					|| p->born_sup - p->born_inf == 0)
					ft_applied_mask(big, mini, p);
				return (1);
			}
			(p->y)++;
		}	
		(p->x)++;
	}
	return (0);
}
