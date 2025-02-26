/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiidenh <khiidenh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:38:42 by khiidenh          #+#    #+#             */
/*   Updated: 2024/12/13 11:50:07 by khiidenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_datatype(va_list *args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(*args, int));
	else if (c == 's')
		count = ft_putstr(va_arg(*args, char *));
	else if (c == 'x')
		count = convert_hex(va_arg(*args, unsigned int), 0);
	else if (c == 'X')
		count = convert_hex(va_arg(*args, unsigned int), 1);
	else if (c == 'p')
		count = convert_void(va_arg(*args, void *));
	else if (c == 'd' || c == 'i')
		count = ft_putnbr(va_arg(*args, int));
	else if (c == 'u')
		count = ft_unsigned_putnbr(va_arg(*args, unsigned int));
	else if (c == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int		result;

	if (!s)
		return (-1);
	count = 0;
	va_start(args, s);
	while (*s != '\0')
	{
		if (*s == '%' && (*s + 1) != '\0')
			result = get_datatype(&args, *++s);
		else
			result = ft_putchar(*s);
		if (result == -1)
		{
			va_end(args);
			return (-1);
		}
		count = count + result;
		s++;
	}
	va_end(args);
	return (count);
}
