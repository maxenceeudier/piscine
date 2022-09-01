/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:07:13 by meudier           #+#    #+#             */
/*   Updated: 2022/03/12 17:40:32 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	first;

	first = 1;
	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') && first)
		{
			str[i] -= 32;
			first = 0;
		}
		else if ((str[i] >= 'A' && str[i] <= 'Z') && !first)
			str[i] += 32;
		if (!(str[i] >= 'a' && str[i] <= 'z')
			&& !(str[i] >= 'A' && str[i] <= 'Z')
			&&!(str[i] >= '0' && str[i] <= '9'))
			first = 1;
		else
			first = 0;
		i++;
	}
	return (str);
}
