/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_extra_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elduran <elduran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:03:23 by elduran           #+#    #+#             */
/*   Updated: 2024/12/06 12:09:57 by elduran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexanbr_lower(unsigned long nbr)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += ft_puthexanbr_lower(nbr / 16);
	if (nbr % 16 < 10)
		count += ft_putchar('0' + (nbr % 16));
	else
		count += ft_putchar('a' + (nbr % 16 - 10));
	return (count);
}

int	ft_puthexanbr_upper(unsigned long nbr)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += ft_puthexanbr_upper(nbr / 16);
	if (nbr % 16 < 10)
		count += ft_putchar('0' + (nbr % 16));
	else
		count += ft_putchar('A' + (nbr % 16 - 10));
	return (count);
}

int	ft_pointer(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
	{
		count += ft_putstr("(nil)");
		return (count);
	}
	count += ft_putstr("0x");
	count += ft_puthexanbr_lower((unsigned long)ptr);
	return (count);
}

int	ft_putnbr(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		count += ft_putnbr(nbr / 10);
	}
	count += ft_putchar('0' + (nbr % 10));
	return (count);
}

int	ft_unsputnbr(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr > 9)
	{
		count += ft_unsputnbr(nbr / 10);
	}
	count += ft_putchar('0' + (nbr % 10));
	return (count);
}
