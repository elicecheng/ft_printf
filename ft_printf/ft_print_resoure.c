/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_resoure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:04:14 by jucheng           #+#    #+#             */
/*   Updated: 2023/07/25 18:04:20 by jucheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned long long ptr)
{
	int	i;

	i = 0;
	if (ptr < 16)
	{
		if (ptr > 9)
			return (ft_putchar('a' + (ptr - 10)));
		return (ft_putchar('0' + ptr));
	}
	else
	{
		i += ft_print_hexa(ptr / 16);
		i += ft_print_hexa(ptr % 16);
	}
	return (i);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	i;

	i = ft_printstr("0x");
	i += ft_print_hexa(ptr);
	return (i);
}

int	ft_print_long_hexa(unsigned int ptr, char format)
{
	int	i;

	i = 0;
	if (ptr < 16)
	{
		if (ptr > 9)
		{
			if (format == 'x')
				return (ft_putchar('a' + (ptr - 10)));
			return (ft_putchar('A' + (ptr - 10)));
		}
		return (ft_putchar('0' + ptr));
	}
	else
	{
		i += ft_print_long_hexa(ptr / 16, format);
		i += ft_print_long_hexa(ptr % 16, format);
	}
	return (i);
}

int	ft_print_undec(unsigned int number)
{
	int	i;

	i = 0;
	if (number < 10)
		return (ft_putchar('0' + number));
	else
	{
		i += ft_print_undec(number / 10);
		i += ft_print_undec(number % 10);
	}
	return (i);
}

int	ft_print_dec(int number)
{
	int	i;

	if (number < 0)
	{
		i = ft_putchar('-');
		i += ft_print_undec(-number);
	}
	else
		i = ft_print_undec(number);
	return (i);
}
