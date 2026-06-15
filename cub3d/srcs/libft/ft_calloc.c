/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 22:06:09 by mvignes           #+#    #+#             */
/*   Updated: 2026/01/30 13:50:51 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*calloc;

	if ((int)nmemb < 0 && (int)size < 0)
		return (NULL);
	calloc = malloc((size * nmemb));
	if (!calloc)
		return (NULL);
	i = 0;
	while (i < (size * nmemb))
	{
		calloc[i] = '\0';
		i++;
	}
	return ((void *)calloc);
}
