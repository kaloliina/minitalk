/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiidenh <khiidenh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:28:48 by khiidenh          #+#    #+#             */
/*   Updated: 2024/12/13 11:40:37 by khiidenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_putnbr(unsigned int n)
{
	int		count;
	char	number;

	count = 0;
	if (n >= 10)
		count += ft_unsigned_putnbr(n / 10);
	number = (n % 10) + '0';
	if (write(1, &number, 1) == -1)
		return (-1);
	count = count + 1;
	return (count);
}
