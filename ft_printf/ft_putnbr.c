/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiidenh <khiidenh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:29:04 by khiidenh          #+#    #+#             */
/*   Updated: 2024/12/12 19:40:03 by khiidenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		count;
	char	number;

	count = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (write(1, "-2147483648", 11));
		else
		{
			count = write(1, "-", 1);
			if (count == -1)
				return (-1);
			n = -n;
		}
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	number = (n % 10) + '0';
	if (write(1, &number, 1) == -1)
		return (-1);
	count = count + 1;
	return (count);
}
