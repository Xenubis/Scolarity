/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:48:47 by mvignes           #+#    #+#             */
/*   Updated: 2026/01/30 13:50:06 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	isvalid(char c, char *base, int len_base)
{
	int	i;

	i = 0;
	while (i < len_base)
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

static int	calcul_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *nptr, char *base)
{
	int	i;
	int	sign;
	int	result;
	int	len_base;

	i = 0;
	sign = 1;
	result = 0;
	len_base = ft_strlen(base);
	if (len_base < 2)
		return (0);
	while (nptr[i] <= 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && isvalid(nptr[i], base, len_base))
	{
		result = result * len_base + calcul_index(nptr[i], base);
		i++;
	}
	return (result * sign);
}

/* int	main(void)
{
	int	i;

	i = ft_atoi_base("ffffff", "0123456789abcdef");
	printf("%d\n", i);
} */
