/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 09:55:07 by meudier           #+#    #+#             */
/*   Updated: 2022/03/13 19:53:19 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hexa(char c)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	write(1, &hexa[c / 16], 1);
	write(1, &hexa[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i = 0;
	int n = sizeof(str);
	while (i < n)
	{
		if (*str < ' ' || *str > '~')
		{
			write (1, "\\", 1);
			ft_print_hexa(*str);
		}
		else
			write (1, str, 1);
		str++;
		i++;
	}
}

int main(){
	char *str="couco\0u vas bien ?";
	ft_putstr_non_printable(str);
	return 0;
}

