/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:18:26 by meudier           #+#    #+#             */
/*   Updated: 2022/03/30 14:22:22 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_check_file(char **map, t_data *data)
{
	int	i;
	int	j;

	if (!size_line(map))
		return (0);
	if (!(data->vide != data->obstacle && data->vide != data->plein
			&& data->obstacle != data->plein))
		return (0);
	if (!data->num_max || !data->plein || !data->vide || !data->obstacle)
		return (0);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(map[i][j] == data->vide || map[i][j] == data->obstacle))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
