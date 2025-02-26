# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khiidenh <khiidenh@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 14:44:50 by khiidenh          #+#    #+#              #
#    Updated: 2025/02/26 14:00:01 by khiidenh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server
FT_PRINTF = ft_printf/libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./ft_printf -I.
SRC_CLIENT = client.c utils.c
SRC_SERVER = server.c utils.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

all: $(FT_PRINTF) $(NAME_CLIENT) $(NAME_SERVER)

$(FT_PRINTF):
	make -C ft_printf

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME_CLIENT): $(OBJ_CLIENT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJ_CLIENT) -L./ft_printf -lftprintf

$(NAME_SERVER): $(OBJ_SERVER) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJ_SERVER) -L./ft_printf -lftprintf

clean:
	make -C ft_printf clean
	rm -f $(OBJ_CLIENT)
	rm -f $(OBJ_SERVER)

fclean: clean
	make -C ft_printf fclean
	rm -f $(NAME_CLIENT)
	rm -f $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re
