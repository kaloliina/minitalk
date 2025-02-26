# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khiidenh <khiidenh@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 14:46:10 by khiidenh          #+#    #+#              #
#    Updated: 2024/12/12 15:27:20 by khiidenh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = 	convert_hex.c    \
		convert_void.c    \
		ft_printf.c    \
		ft_putchar.c    \
		ft_putnbr.c    \
		ft_putstr.c    \
		ft_strlen.c    \
		ft_unsigned_putnbr.c    \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
