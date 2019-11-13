# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: equiana <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 19:12:46 by equiana           #+#    #+#              #
#    Updated: 2019/11/13 17:20:47 by equiana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

CC = clang

SRC = main.c float.c ft_atoi.c printf.c ft_putchar.c ft_putstr.c ft_strlen.c parse.c \
	  support.c display.c ft_itoa_base.c ft_itoa_base_u.c char.c string.c octet.c hex.c\
	  pointer.c integer.c unsigned.c ft_itoa_base_l.c long_int.c short_int.c ft_itoa_base_h.c

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
