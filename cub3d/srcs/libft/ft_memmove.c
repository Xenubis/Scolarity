/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:59:40 by mvignes           #+#    #+#             */
/*   Updated: 2026/01/30 13:51:23 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*tmp_dest;
	unsigned const char	*tmp_src;

	if (!dest && !src)
		return (NULL);
	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned const char *)src;
	i = 0;
	if ((dest > src) && (n > 0))
	{
		while (0 < --n)
			tmp_dest[n] = tmp_src[n];
		tmp_dest[n] = tmp_src[n];
	}
	else
	{
		while (i < n)
		{
			tmp_dest[i] = tmp_src[i];
			i++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	dest[40];
	char	*src;

	src = "HELLO !";
	ft_memmove(dest, src, 5);
	dest[i] = '\0';
	printf("%s", dest);
	return (0);
}*/