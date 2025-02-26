/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiidenh <khiidenh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:31:14 by khiidenh          #+#    #+#             */
/*   Updated: 2024/12/12 20:28:14 by khiidenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_hex(unsigned int n, int casecheck)
{
	char			hexadecimal[9];
	int				count;
	int				i;

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
