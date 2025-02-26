/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiidenh <khiidenh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:10:09 by khiidenh          #+#    #+#             */
/*   Updated: 2025/02/26 14:55:26 by khiidenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_received = 0;

static void	return_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	(void)*info;
	if (sig == SIGUSR1)
		g_received = 1;
}

static void	send_binary(unsigned char bit, pid_t pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_received = 0;
		if (bit & (1 << i))
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error("Signal was not delivered!");
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error("Signal was not delivered!");
		}
		while (g_received == 0)
		{
			if (usleep(100000) == 0 && g_received == 0)
				ft_error("Timeout: Server failed to send signal back!");
		}
		i--;
	}
}

static void	send_signal(char *str, pid_t pid)
{
	int				i;
	unsigned char	bit;

	i = 0;
	while (str[i] != '\0')
	{
		bit = str[i];
		send_binary(bit, pid);
		i++;
	}
	bit = 0;
	send_binary(bit, pid);
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	sa;

	if (argc != 3)
		ft_error("Expected Input: ./client <PID> <Message>");
	sa.sa_sigaction = &return_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_error("Sigaction failure");
	pid = ft_atoi(argv[1]);
	validate_pid(argv[1], pid);
	send_signal(argv[2], pid);
	if (g_received == 1)
	{
		if (ft_printf("Message received!\n") == -1)
			ft_error("Error: Ft_printf function failed!");
	}
	return (0);
}
