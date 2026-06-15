/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 08:26:42 by mvignes           #+#    #+#             */
/*   Updated: 2026/01/30 13:51:26 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_putchar_printf(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_printf(char *s)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_printf(s[i]);
		i++;
	}
	return (i);
}
