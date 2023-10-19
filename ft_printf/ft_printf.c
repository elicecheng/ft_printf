/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheng <jucheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:27:00 by jucheng           #+#    #+#             */
/*   Updated: 2023/08/24 16:13:40 by jucheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char str)
{
	if (str == 'c')
		return (ft_putchar(va_arg (args, int)));
	else if (str == 's')
		return (ft_printstr(va_arg (args, char *)));
	else if (str == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long long)));
	else if (str == 'd' || str == 'i')
		return (ft_print_dec(va_arg (args, int)));
	else if (str == 'u')
		return (ft_print_undec(va_arg (args, unsigned int)));
	else if (str == 'x' || str == 'X')
		return (ft_print_long_hexa (va_arg (args, unsigned int), str));
	else if (str == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		print_len;

	i = 0;
	print_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += ft_formats(args, str[i + 1]);
			i++;
		}
		else
		{
			print_len += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (print_len);
}

int	main()
 {
 	//ft_printf("%c, %s, %p, asdfewqrdsa %%", 'e', "123", (void *)123);
	ft_printf("%%%%%%\n");
 	//printf("%d\n", printf(" %p ", -1));
 	//printf("%d\n", ft_printf(" %p ", -1));
 	return (0);
 }
