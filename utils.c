/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiidenh <khiidenh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:00:01 by khiidenh          #+#    #+#             */
/*   Updated: 2025/02/26 11:37:12 by khiidenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit (1);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		check;
	long	result;

	i = 0;
	check = 1;
	result = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			check = -1 * check;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)result * check);
}

void	validate_pid(char *arg, int pid)
{
	while (*arg != '\0')
	{
		if (!(*arg >= '0' && *arg <= '9'))
			ft_error("PID should consist only of numbers!");
		arg++;
	}
	if (kill(pid, 0) == -1)
		ft_error("Incorrect PID!");
}
