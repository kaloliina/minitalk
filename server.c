/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiidenh <khiidenh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:22:41 by khiidenh          #+#    #+#             */
/*   Updated: 2025/02/26 14:02:26 by khiidenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	byte;
	static int				bit_count;

	(void)ucontext;
	byte = (byte << 1) | (sig == SIGUSR2);
	bit_count++;
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_error("Signal was not delivered!");
	if (bit_count == 8)
	{
		if (byte == 0)
		{
			if (write(1, "\n", 1) == -1)
				ft_error("Error: Write function failed!");
		}
		else
		{
			if (write(1, &byte, 1) == -1)
				ft_error("Error: Write function failed!");
		}
		byte = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	if (ft_printf("Server PID: ") == -1)
		ft_error("Error: Ft_printf function failed!");
	if (ft_printf("%d\n", getpid()) == -1)
		ft_error("Error: Ft_printf function failed!");
	sa.sa_sigaction = &handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_error("Sigaction failure");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_error("Sigaction failure");
	while (1)
		pause();
	return (0);
}
