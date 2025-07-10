/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:25:19 by mlemee            #+#    #+#             */
/*   Updated: 2025/06/28 14:52:30 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft.h"

static int	ft_count_word(const char *s, char c)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static int	ft_wordlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**ft_free_all(char **tab, int i)
{
	while (i--)
		free(tab[i]);
	free(tab);
	return (NULL);
}

static char	**fill_tab(char **tab, const char *s, char c, int words)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (j < words)
	{
		while (s[i] == c)
			i++;
		len = ft_wordlen(s + i, c);
		tab[j] = malloc(sizeof(char) * (len + 1));
		if (!tab[j])
			return (ft_free_all(tab, j), NULL);
		ft_strlcpy(tab[j++], s + i, len + 1);
		i += len;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;

	if (!s)
		return (NULL);
	words = ft_count_word(s, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	return (fill_tab(tab, s, c, words));
}

// #include <stdio.h>
// #include <stdlib.h>
// int	main(int argc, char *argv[])
// {
// 	if (argc == 2)
// 	{
// 		int i = 0;
// 		char **bis = ft_split(argv[1], ',');
// 		if (!bis)
// 			return (printf("ERREUR/n"));
// 		while (bis[i])
// 		{
// 			printf("%s\n", bis[i]);
// 			i ++;
// 		}
// 		free(bis);
// 		}
// }
