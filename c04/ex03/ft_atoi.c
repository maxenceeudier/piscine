/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 09:54:42 by meudier           #+#    #+#             */
/*   Updated: 2022/03/14 12:48:55 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	sign;
	int	nbr;

	sign = 1;
	nbr = 0;
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
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + *str - '0';
		str++;
	}
	return (sign * nbr);
}
#include <unistd.h>

void	ft_putnbr(int nbr)
{
	char	temp;
	long	n;

	n = nbr;
	if (n < 0)
	{
		write (1, "-", 1);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	temp = n % 10 + '0';
	write (1, &temp, 1);
}
int main(){
	int a = ft_atoi("--2147483648");
	ft_putnbr(a);
	return 0;
}
