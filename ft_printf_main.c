/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elduran <elduran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:03:14 by elduran           #+#    #+#             */
/*   Updated: 2024/12/06 14:29:17 by elduran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int a_func(int i, int j, ...)
{
	int x = 1;
	va_list	va_args;
	va_start(va_args, j);
	while (i > 0)
	{
		x = x * va_arg(va_args, int);
		i--;
	}
	x = j*x;
	va_end(va_args);
	return (x);
}

int	main(void)
{
	int	count = 0;
	count = printf("%c\n" "%s\n", 'A', "Hello, World!");
	printf("%i\n", count);
	count = ft_printf("%c\n" "%s\n", 'A', "Hello, World!");
	printf("%i\n", count);

	printf("%s\n", ".....................................");

	printf("%c\n", 'A');
	ft_printf("%c\n", 'A');

	printf("%s\n", "Hello, World!");
	ft_printf("%s\n", "Hello, World!");

	printf("%d\n", 12345);
	ft_printf("%d\n", 12345);

	printf("%u\n", 4294967295U);
	ft_printf("%u\n", 4294967295U);

	printf("%x\n", 255);
	ft_printf("%x\n", 255);

	printf("%X\n", 255);
	ft_printf("%X\n", 255);
	
	int	a = 42;
	printf("%p\n", &a);
	ft_printf("%p\n", &a);

	int	*b = NULL;
	printf("%p\n", b);
	ft_printf("%p\n", b);

	printf("%%\n");
	ft_printf("%%\n");

	printf("%i", a_func(3, -1, 5, 6, 7));
	
	return (0);
}