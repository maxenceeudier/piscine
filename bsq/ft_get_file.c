/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:43:30 by meudier           #+#    #+#             */
/*   Updated: 2022/03/30 14:43:36 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#define FILE_SIZE 1

int	file_size(char *file_name)
{
	int		fd;
	int		i;
	char	file[FILE_SIZE + 1];

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	while (read(fd, file, FILE_SIZE))
		i++;
	close (fd);
	return (i);
}

char	*ft_get_file(char *file_to_read)
{
	int		fd;
	int		rtr;
	char	*file;
	int		size;

	size = file_size(file_to_read);
	fd = open(file_to_read, O_RDONLY);
	file = malloc(size + 1);
	if (!file)
		return (NULL);
	rtr = read(fd, file, size);
	if (fd == -1 || rtr == -1)
		return (NULL);
	file[rtr] = 0;
	close(fd);
	return (file);
}

char	*ft_read_stdin(void)
{
	int		i;
	char	buf[4096];

	i = 0;
	while (read(0, &buf[i], 1))
	{
		buf[i + 1] = '\0';
		i++;
	}
	return (ft_strdup(buf));
}
