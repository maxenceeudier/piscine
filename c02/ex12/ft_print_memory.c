/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:53:46 by meudier           #+#    #+#             */
/*   Updated: 2022/03/13 12:52:01 by meudier          ###   ########.fr       */
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

void	ft_print_hexa_addr(unsigned long addr)
{
	char	tab[17];
	char	*hexa;
	int		i;

	tab[16] = '0';
	hexa = "0123456789abcdef";
	i = 1;
	while (i < 17)
	{
		if (addr)
		{
			tab[16 - i] = hexa[addr % 16];
			addr /= 16;
		}
		else
			tab[16 - i] = '0';
		i++;
	}
	write (1, tab, 16);
	write (1, ": ", 2);
}

void	ft_print_line(void *addr, unsigned int size)
{
	unsigned long	addrs;
	char			*str;
	unsigned int	i;

	addrs = (unsigned long)addr;
	str = (char *)addr;
	ft_print_hexa_addr(addrs);
	i = 0;
	while (i < size)
	{
		ft_print_hexa(str[i]);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	if (size < 16)
		write(1, " ",1);
	i = 0;
	while (i < size)
	{
		if (str[i] < ' ' || str[i] > '~')
			write (1, ".", 1);
		else
			write (1, &str[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size / 16)
	{
		ft_print_line(addr, 16);
		addr += 16;
		i++;
	}
	ft_print_line(addr, size % 16);
	return (addr);
}

int main(){
	char *str="bomjour les aminches\n\n\nc est fouu\n tout \n";
	ft_print_memory((void *)str,41);
	return 0;
}
