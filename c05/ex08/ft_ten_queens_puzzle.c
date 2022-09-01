/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:22:20 by meudier           #+#    #+#             */
/*   Updated: 2022/03/19 13:29:57 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_col(char *tab, char queen, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (queen == tab[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_diag(char *tab, char queen, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (queen - tab[index - 1 - i] == 1 + i
			|| queen - tab[index - 1 - i] == -1 - i)
			return (0);
		i++;
	}
	return (1);
}

void	ft_init_tab(char *tab)
{
	int	i;

	i = 0;
	while (i <= 10)
	{
		tab[i] = 0;
		i++;
	}
}

int	ft_queen_recursive(char *tab, int index)
{
	char	queen;
	int		count;

	count = 0;
	queen = '0';
	while (queen <= '9')
	{
		if (check_col(tab, queen, index) && check_diag(tab, queen, index))
		{
			tab[index] = queen;
			if (index < 9)
				count += ft_queen_recursive(tab, index + 1);
			else if (index == 9)
			{
				write (1, tab, 10);
				write (1, "\n", 1);
				count = 1;
			}
			else
				break ;
		}
		queen++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	char	tab[11];
	int		count;

	ft_init_tab(tab);
	count = ft_queen_recursive(tab, 0);
	return (count);
}

#include <stdio.h>
int main()
{
    int a = ft_ten_queens_puzzle();
    printf("%d",a);
    return 0;
}
