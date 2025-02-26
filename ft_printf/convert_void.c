/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_void.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiidenh <khiidenh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:31:11 by khiidenh          #+#    #+#             */
/*   Updated: 2024/12/13 11:10:52 by khiidenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_voidhex(uintptr_t n, int casecheck)
{
	char		hexadecimal[17];
	int			count;
	int			i;

	count = 0;
	i = 0;
	if (n == 0)
		return (ft_putchar('0'));
	while (n != 0)
	{
		if ((n % 16) < 10)
			hexadecimal[i++] = (n % 16) + '0';
		else if (casecheck == 1)
			hexadecimal[i++] = (n % 16) + 'A' - 10;
		else
			hexadecimal[i++] = (n % 16) + 'a' - 10;
		n = n / 16;
	}
	while (i > 0)
	{
		if (ft_putchar(hexadecimal[--i]) == -1)
			return (-1);
		count = count + 1;
	}
	return (count);
}

int	convert_void(void *ptr)
{
	int	result;

	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	if (write(1, "0x", 2) == -1)
		return (-1);
	result = convert_voidhex((uintptr_t)ptr, 0);
	if (result == -1)
		return (-1);
	return (result + 2);
}
