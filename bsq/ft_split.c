/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meudier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:18:24 by meudier           #+#    #+#             */
/*   Updated: 2022/03/30 14:44:06 by meudier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

int	char_is_charset(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i] && c)
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_get_number_of_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (char_is_charset(str[i], charset) && str[i])
			i++;
		if (!char_is_charset(str[i], charset) && str[i])
		{
			count++;
			while (!char_is_charset(str[i], charset) && str[i])
				i++;
		}
	}	
	return (count);
}

char	*ft_get_word(int *index, char *str, char *charset)
{
	int		len;
	int		i;
	char	*word;

	i = 0;
	len = 0;
	while (char_is_charset(str[*index], charset) && str[*index])
		(*index)++;
	while (!char_is_charset(str[*index + len], charset) && str[*index + len])
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[*index];
		(*index)++;
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		j;
	int		num_words;

	num_words = ft_get_number_of_words(str, charset);
	tab = malloc(sizeof(char *) * (num_words + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (i < num_words)
	{
		tab[i] = ft_get_word(&j, str, charset);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
