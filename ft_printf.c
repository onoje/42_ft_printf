/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elduran <elduran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:03:29 by elduran           #+#    #+#             */
/*   Updated: 2024/12/06 14:33:46 by elduran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str == NULL)
	{
		count += ft_putstr("(null)");
		return (count);
	}
	while (str[i] != '\0')
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}

static int	ft_printf_format(const char format, va_list va_args)
{
	int	count;

	count = 0;
	if (format == '%')
		count += ft_putchar('%');
	else if (format == 'c')
		count += ft_putchar(va_arg(va_args, int));
	else if (format == 's')
		count += ft_putstr(va_arg(va_args, char *));
	else if (format == 'p')
		count += ft_pointer(va_arg(va_args, void *));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(va_args, int));
	else if (format == 'u')
		count += ft_unsputnbr(va_arg(va_args, unsigned int));
	else if (format == 'x')
		count += ft_puthexanbr_lower(va_arg(va_args, unsigned int));
	else if (format == 'X')
		count += ft_puthexanbr_upper(va_arg(va_args, unsigned int));
	else
	{
		count += ft_putchar('%');
		count += ft_putchar(format);
	}
	return (count);
}

int	ft_printf(const char *format_type, ...)
{
	int		i;
	int		count;
	va_list	va_args;

	i = 0;
	count = 0;
	va_start(va_args, format_type);
	while (format_type[i] != '\0')
	{
		if (format_type[i] == '%' && format_type[i + 1] != '\0')
		{
			count += ft_printf_format(format_type[i + 1], va_args);
			i++;
		}
		else
			count += ft_putchar(format_type[i]);
		i++;
	}
	va_end(va_args);
	return (count);
}
