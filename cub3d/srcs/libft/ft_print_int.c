/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:51:01 by mvignes           #+#    #+#             */
/*   Updated: 2026/01/30 13:51:27 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
// Pour tout les int, long, ... sauf pointeur
int	ft_putnbr_printf(long long nb, char *base)
{
	int		i;
	long	size;

	i = 0;
	size = ft_strlen_printf(base);
	if (nb < 0)
	{
		i += ft_putchar_printf('-');
		nb *= -1;
	}
	if (nb >= size)
		i += ft_putnbr_printf(nb / size, base);
	i += ft_putchar_printf(base[nb % size]);
	return (i);
}

// Pour les pointers
int	ft_pointeur(uintptr_t p, char *base)
{
	int	len;

	len = 0;
	if (!p)
	{
		len += ft_putstr_printf("(nil)");
		return (len);
	}
	ft_putstr_printf("0x");
	len = 2;
	len += ft_pointer_printf(p, base);
	return (len);
}

int	ft_pointer_printf(unsigned long nb, char *base)
{
	int				i;
	unsigned long	size;

	i = 0;
	size = ft_strlen_printf(base);
	if ((long)nb < 0)
	{
		i += ft_putchar_printf('-');
		nb *= -1;
	}
	if (nb >= size)
		i += ft_putnbr_printf(nb / size, base);
	i += ft_putchar_printf(base[nb % size]);
	return (i);
}
/* int	ft_putnbr_unsigned_printf(unsigned int nb)
{
	int i;

	i = 0;
	if (nb > 9)
		i += ft_putnbr_unsigned_printf(nb / 10);
	i += ft_putchar_printf(nb % 10 + '0');
	return (i);
} */