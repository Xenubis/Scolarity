/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:23:09 by mvignes           #+#    #+#             */
/*   Updated: 2026/01/30 13:51:28 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
normal;
1. %c = simple caratectaire
2. %s = chaine de carataire
3. %p = pointeur
4. %d = decimal
5. %i = entier
6. %u = unsigned decimal
7. %x = hexadecimal (base 16) min
8. %X = hexadecimal (base 16) MAJ
9. %% = en poucentage

flags;
1. #
2. ' '
3. +
*/
int	ft_condition_printf(char formati, va_list args)
{
	int	calcul;

	calcul = 0;
	if (formati == 'c')
		calcul += ft_putchar_printf(va_arg(args, int));
	else if (formati == 's')
		calcul += ft_putstr_printf(va_arg(args, char *));
	else if (formati == 'p')
		calcul += ft_pointeur(va_arg(args, uintptr_t), "0123456789abcdef");
	else if (formati == 'd' || formati == 'i')
		calcul += ft_putnbr_printf(va_arg(args, int), "0123456789");
	else if (formati == 'u')
		calcul += ft_putnbr_printf(va_arg(args, unsigned int), "0123456789");
	else if (formati == 'x')
		calcul += ft_putnbr_printf(va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (formati == 'X')
		calcul += ft_putnbr_printf(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	else if (formati == '%')
		calcul += ft_putchar_printf('%');
	return (calcul);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total;
	int		i;

	va_start(args, format);
	i = 0;
	total = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			total += ft_condition_printf(format[i + 1], args);
			i++;
		}
		else
			total += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (total);
}
