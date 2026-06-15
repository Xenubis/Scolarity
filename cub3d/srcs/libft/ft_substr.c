/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 22:31:00 by mvignes           #+#    #+#             */
/*   Updated: 2026/01/30 13:52:00 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	size;

	if (start > ft_strlen(s))
	{
		new = malloc(sizeof(char) * 1);
		if (!new)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	if (len > ft_strlen(&s[start]))
		size = ft_strlen(&s[start]);
	else
		size = len;
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	i = 0;
	while ((s[start] != '\0') && (i < size))
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	size;

	size = ft_strlen(&s[start]);
	if (size > len)
		size = len;
	if (start > ft_strlen(s))
		size = 0;
	new = malloc(sizeof(char) * (size) + 1);
	if (!new)
		return (NULL);
	if (!s || !len || (start + 1 > ft_strlen(s)))
	{
		new[0] = '\0';
		return(new);
	}
	i = 0;
	while ((s[start] != '\0') && (i < size))
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}

int	main(void)
{
	char *s = ft_substr("hola", -1, 0);
	printf("%s", s);
}*/
