/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:29:06 by meudier           #+#    #+#             */
/*   Updated: 2022/03/28 11:42:16 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int	do_op(int a, int b, char *operator)
{
	if (operator[1] != 0)
		return (0);
	if (*operator == '+')
		return (a + b);
	else if (*operator == '-')
		return (a - b);
	else if (*operator == '/')
		return (a / b);
	else if (*operator == '*')
		return (a * b);
	else if (*operator == '%')
		return (a % b);
	return (0);
}

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	int		rslt;

	if (argc != 4)
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	if (b == 0 && argv[2][0] == '/')
	{
		write (1, "Stop : division by zero\n", 24);
		return (0);
	}
	if (b == 0 && argv[2][0] == '%')
	{
		write (1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	rslt = do_op(a, b, argv[2]);
	ft_putnbr(rslt);
	write (1, "\n", 1);
	return (0);
}
