/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data_and_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:00:08 by meudier           #+#    #+#             */
/*   Updated: 2022/03/30 14:28:48 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	size_line(char **map)
{
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != size)
			return (0);
		i++;
	}
	return (size);
}

int	the_smaller(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

char	**ft_create_map(char *file)
{
	int		i;
	char	**map;

	i = 0;
	while (file[i] != '\n')
		i++;
	if (file[i + 1])
		map = ft_split(file + i + 1, "\n");
	else
		map = NULL;
	return (map);
}

t_data	*ft_create_data(char *file, int num_col_max)
{
	int		i;
	t_data	*data;

	i = 0;
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	while (file[i] != '\n')
		i++;
	while (file[i - 1] == ' ')
		i--;
	data->plein = file[i - 1];
	data->obstacle = file[i - 2];
	data->vide = file[i - 3];
	file[i - 3] = 0;
	data->num_max = the_smaller(ft_atoi(file), num_col_max);
	data->born_sup = data->num_max;
	data->born_inf = 1;
	return (data);
}

int	get_data_and_map(char *file_name, char ***map, t_data **data)
{
	char	*file;
	int		i;

	i = 0;
	if (!file_name)
		file = ft_read_stdin();
	else
		file = ft_get_file(file_name);
	if (!file)
		return (0);
	*map = ft_create_map(file);
	if (!*map)
		return (0);
	*data = ft_create_data(file, size_line(*map));
	while ((*map)[i])
		i++;
	if (!ft_check_file(*map, *data) || i != ft_atoi(file))
		return (0);
	free(file);
	return (1);
}
