# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: equiana <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 19:12:46 by equiana           #+#    #+#              #
#    Updated: 2019/11/19 18:54:14 by equiana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = printf.c parse.c support.c display.c \
	  char.c string.c string_e.c pointer.c \
	  integer.c long_int.c short_int.c short_short.c \
	  octet.c long_oct.c short_oct.c short_short_oct.c \
	  unsigned.c long_uns.c short_uns.c short_short_uns.c \
	  hex.c long_hex.c short_hex.c short_short_hex.c \
	  float.c long_float.c 

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/

HEAD = printf.h

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(CFLAGS) -I $(HEAD) -o $@ -c $<

clean:
	$(MAKE) clean -C $(LIBFT)
	rm -rf $(OBJ)
	
fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	rm -rf $(NAME)
	
re: fclean all
