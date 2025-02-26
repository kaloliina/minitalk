/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiidenh <khiidenh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:32:23 by khiidenh          #+#    #+#             */
/*   Updated: 2024/12/13 11:45:14 by khiidenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *s, ...);
int		convert_hex(unsigned int n, int casecheck);
int		convert_void(void *ptr);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *s);
int		ft_unsigned_putnbr(unsigned int n);

#endif
