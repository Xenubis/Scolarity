/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 22:26:32 by mvignes           #+#    #+#             */
/*   Updated: 2026/01/30 13:51:01 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_strlenint(long n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 9)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	long	m;
	size_t	size;

	m = n;
	size = ft_strlenint(m);
	nbr = malloc(sizeof(char) * (size + 1));
	if (!nbr)
		return (0);
	nbr[size] = '\0';
	if (m < 0)
	{
		nbr[0] = '-';
		m *= -1;
	}
	size--;
	while (m > 9)
	{
		nbr[size] = (m % 10) + '0';
		m = (m / 10);
		size--;
	}
	nbr[size] = (m % 10) + '0';
	return (nbr);
}
