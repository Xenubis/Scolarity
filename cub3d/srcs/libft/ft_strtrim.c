/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 22:30:42 by mvignes           #+#    #+#             */
/*   Updated: 2026/03/30 21:45:00 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_verif_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (0);
		i++;
	}
	return (1);
}

static int	ft_start_end(char const *s1, char const *set, int position)
{
	int	i;

	if (position == 0)
	{
		i = 0;
		while (!ft_verif_set(s1[i], set))
			i++;
		return (i);
	}
	if (position == 1)
	{
		i = ft_strlen(s1) - 1;
		while (!ft_verif_set(s1[i], set))
			i--;
		return (i);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cpy;
	int		start;
	int		end;

	if (!s1)
	{
		cpy = ft_strdup("");
		return (cpy);
	}
	else if (ft_strlen(set) == 0)
		cpy = ft_strdup((char *)s1);
	else
	{
		start = ft_start_end(s1, set, 0);
		end = ft_start_end(s1, set, 1);
		cpy = ft_substr(s1, start, (end - start + 1));
	}
	return (cpy);
}
/*
int	main(void)
{
	char	*r;

	r = ft_strtrim("abababatestabababa", "ab");
	printf("%s\n", r);
}


char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cpy;
	int		i;
	int		start;
	int		size;

	if (!s1)
	{
		cpy = ft_strdup("");
		return (cpy);
	}
	start = 0;
	size = 0;
	i = -1;
	while (!ft_verif_set(s1[++i], set))
		start += ft_verif_set(s1[i], set);
	i = ft_strlen(s1) + 1;
	while (!ft_verif_set(s1[--i], set))
		size -= ft_verif_set(s1[i], set);
	cpy = malloc(sizeof(char) * (size + 1));
	if (!cpy)
		return (0);
	cpy = ft_substr(s1, start, size);
	return (cpy);
}













static int	ft_verif_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (0);
		i++;
	}
	return (1);
}

static int	ft_sup_set_l(char const *s, char const *set)
{
	int	i;

	i = 0;
	while (ft_verif_set(s[i], set) == 0)
		i++;
	return (i);
}

static int	ft_sup_set_r(char const *s, char const *set)
{
	int	i;

	i = (ft_strlen(s) - 1);
	while (ft_verif_set(s[i], set) == 0)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cpy;
	int		i;
	int		start;
	int		size;

	start = ft_sup_set_l(s1, set);
	size = ft_sup_set_r(s1, set) - start;
	cpy = malloc(sizeof(char) * (size + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	cpy[i] = '\0';
	if (!s1)
		return (cpy);
	while (i < size + 1)
	{
		cpy[i] = s1[start];
		i++;
		start++;
	}
	cpy[i] = '\0';
	return (cpy);
}*/
