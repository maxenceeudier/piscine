/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:01:36 by meudier           #+#    #+#             */
/*   Updated: 2022/03/14 15:53:34 by meudier          ###   ########.fr       */
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
		if (base[i] == '+' || base[i] == '-')
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

void	ft_putnbr_base(int nbr, char *base)
{
	char	temp;
	long	n;
	int		len;

	len = ft_strlen(base);
	n = nbr;
	if (!(ft_base_is_conforme(base)))
		return ;
	if (n < 0)
	{
		write (1, "-", 1);
		n *= -1;
	}
	if (n / len)
		ft_putnbr_base(n / len, base);
	temp = base[n % len];
	write (1, &temp, 1);
}
/*
int main(){
	ft_putnbr_base(127,"01");
	return (0);
}*/
