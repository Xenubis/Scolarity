/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:35:46 by mvignes           #+#    #+#             */
/*   Updated: 2026/01/30 13:51:47 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	value;

	if (size <= ft_strlen(dest))
		value = ft_strlen(src) + size;
	else
		value = ft_strlen(src) + ft_strlen(dest);
	if (size <= 0)
		return (ft_strlen(src));
	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (value);
}
/*
#include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	char dest[] = "hello";
	char *src;

	src = "HELLO !";
	printf("%zu\n", strlcat(dest, src, 13));
	printf("%s", dest);
	return (0);
}*/