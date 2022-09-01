/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:50:47 by meudier           #+#    #+#             */
/*   Updated: 2022/03/21 22:03:33 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

char	*ft_itoa_base(int nbr, char *base);

int	ft_base_is_conforme(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-'
			|| base[i] == ' ' || base[i] == '\t'
			|| base[i] == '\n' || base[i] == '\r'
			|| base[i] == '\v' || base[i] == '\f')
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	else
		return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_is_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	int		nbr;
	int		len;

	len = ft_strlen(base);
	sign = 1;
	nbr = 0;
	if (!ft_base_is_conforme(base))
		return (0);
	while (*str == ' ' || *str == '\t'
		|| *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_is_base(*str, base) != -1)
	{
		nbr = nbr * len + ft_is_base(*str, base);
		str++;
	}	
	return (sign * nbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nb;

	if (!nbr || !base_from || !base_to)
		return (NULL);
	if (!ft_base_is_conforme(base_from) || !ft_base_is_conforme(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(nb, base_to));
}

#include <stdio.h>
   int main(){
   char *str = ft_convert_base("", "01", "0123456789");
   printf("%s", str);
   }
