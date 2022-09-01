/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:06:23 by meudier           #+#    #+#             */
/*   Updated: 2022/03/15 13:17:17 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
	int	sign;
	int	nbr;
	int	len;

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
/*
#include <stdio.h>
int	main(){
	int a = ft_atoi_base("   \n--+--001167","01");
	printf("%d",a);
}*/
