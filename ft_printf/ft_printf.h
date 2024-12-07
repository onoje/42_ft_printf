/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elduran <elduran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:03:34 by elduran           #+#    #+#             */
/*   Updated: 2024/12/06 14:33:35 by elduran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_printf(const char *format_type, ...);

int	ft_puthexanbr_lower(unsigned long nbr);
int	ft_puthexanbr_upper(unsigned long nbr);
int	ft_pointer(void *ptr);
int	ft_putnbr(long nbr);
int	ft_unsputnbr(unsigned int nbr);

#endif
