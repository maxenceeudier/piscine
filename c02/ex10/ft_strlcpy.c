/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 09:14:15 by meudier           #+#    #+#             */
/*   Updated: 2022/03/12 17:38:47 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char*src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (size != 0 && src[i] && (i < size -1))
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = 0;
	while (src[i])
		i++;
	return (i);
}
