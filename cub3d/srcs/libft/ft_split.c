/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 22:28:43 by mvignes           #+#    #+#             */
/*   Updated: 2026/05/22 11:17:30 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	split(char **total_words, char const *s, char c, int nb_words)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (s[i])
	{
		if (s[i] && s[i] == c)
			start = i + 1;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			total_words[nb_words] = malloc(sizeof(char) * (i - start + 2));
			if (!total_words[nb_words])
			{
				while (nb_words-- > 0)
					free(total_words[nb_words]);
				return (0);
			}
			ft_strlcpy(total_words[nb_words], &s[start], (i - start + 2));
			nb_words++;
		}
		i++;
	}
	total_words[nb_words] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**total_words;
	int		nb_words;
	int		size;

	if (!s)
		return (0);
	size = count_words(s, c);
	total_words = malloc(sizeof(char *) * (size + 1));
	if (!total_words)
		return (0);
	nb_words = 0;
	if (!split(total_words, s, c, nb_words))
		return (0);
	return (total_words);
}
