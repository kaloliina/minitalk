/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiidenh <khiidenh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:55:51 by khiidenh          #+#    #+#             */
/*   Updated: 2025/02/26 11:37:21 by khiidenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"

void	ft_error(char *str);
int		ft_atoi(const char *nptr);
void	validate_pid(char *arg, int pid);

#endif
