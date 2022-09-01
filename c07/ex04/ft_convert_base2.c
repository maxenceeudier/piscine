/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:35:02 by meudier           #+#    #+#             */
/*   Updated: 2022/03/21 22:01:32 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

int	ft_strlen(char *str);
int	ft_base_is_conforme(char *base);

int	size_of_number(long nbr, int len)
{
	int	i;

	i = 1;
	while (nbr / len)
	{
		nbr /= len;
		i++;
	}
	return (i);
}

void	rev_tab(char **tab)
{
	int		i;
	int		len;
	char	temp;

	len = ft_strlen(*tab);
	i = 0;
	while (i < len / 2)
	{
		temp = (*tab)[i];
		(*tab)[i] = (*tab)[len - 1 - i];
		(*tab)[len - 1 - i] = temp;
		i++;
	}
}

int	put_in_str(char *str, long long n, int len, char *base)
{
	int	i;

	i = 0;
	while (n / len)
	{
		str[i++] = base[n % len];
		n /= len;
	}
	str[i] = base[n % len];
	return (i);
}

char	*ft_itoa_base(int nbr, char *base)
{
	int			len;
	char		*str;
	int			sign;
	int			i;
	long long	n;

	n = nbr;
	sign = 0;
	if (n < 0)
	{
		n *= -1;
		sign = 1;
	}
	len = ft_strlen(base);
	str = malloc(sizeof(char) * (size_of_number(n, len) + sign + 1));
	if (!(ft_base_is_conforme(base)))
		return (NULL);
	i = put_in_str(str, n, len, base);
	if (sign)
		str[i + 1] = '-';
	rev_tab(&str);
	return (str);
}
