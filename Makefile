# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: equiana <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 19:12:46 by equiana           #+#    #+#              #
#    Updated: 2019/11/16 15:16:24 by equiana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

CC = clang

SRC = main.c ft_atoi.c printf.c ft_putchar.c ft_putstr.c ft_strlen.c parse.c \
	  support.c display.c ft_itoa_base.c char.c string.c pointer.c \
	  integer.c long_int.c short_int.c short_short.c \
	  octet.c long_oct.c short_oct.c short_short_oct.c \
	  unsigned.c long_uns.c short_uns.c short_short_uns.c \
	  hex.c long_hex.c short_hex.c short_short_hex.c \
	  float.c long_float.c 

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f printf.h.gch
	@/bin/rm -f libft.h.gch

fclean: clean
	@/bin/rm -f $(NAME)

re: clean
	@/bin/rm -f $(NAME)
