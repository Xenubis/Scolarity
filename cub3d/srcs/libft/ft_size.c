/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:39:19 by mvignes           #+#    #+#             */
/*   Updated: 2026/01/30 13:51:37 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strlen_printf(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strlenint_printf(long n)
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
