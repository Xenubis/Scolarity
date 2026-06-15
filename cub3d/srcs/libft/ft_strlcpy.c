/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:28:13 by mvignes           #+#    #+#             */
/*   Updated: 2026/03/17 14:17:28 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else
	{
		return (ft_strlen(src));
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

// size_t	ft_strlcpy(char *dest, const char *src, size_t size)
// {
// 	size_t	i;
// 	size_t	len_src;

// 	if (!src)
// 		return (0);
// 	len_src = ft_strlen(src);
// 	if (size == 0 || !dest)
// 		return (len_src);
// 	i = 0;
// 	while (src[i] != '\0' && i < (size - 1))
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (len_src);
// }

/*
#include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	char	dest[20];
	char	*src;

	src = "HELLO !";
	printf("%zu\n",ft_strlcpy(dest, src, 0));
	printf("%s", dest);
	return (0);
}*/