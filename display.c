/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:08:23 by equiana           #+#    #+#             */
/*   Updated: 2019/11/08 19:49:59 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

void ft_display_char(va_list ap)
{
	char c;

	c = (char)va_arg(ap, int);
	write(1, &c, 1);
}

void ft_display_str(va_list ap)
{
	ft_putstr(va_arg(ap, char*));
}

void ft_display_int(va_list ap, t_param *prm)
{
	char s;

	s = prm->type;
	if (s == 'd' || s == 'i')
		if (prm->mod == 'l')
			ft_putnbr_l(va_arg(ap, long int));
		else
			ft_putnbr(va_arg(ap, int));
	else if (s == 'u')
		ft_putnbr_u(va_arg(ap, unsigned int));
	else if (s == 'd' || s == 'i')
		ft_putnbr_l(va_arg(ap, long int));
	else if (s == 'x' || s == 'X')
		ft_putnbr_hex(va_arg(ap, int));
	else if (s == 'o')
		ft_putnbr_oct(va_arg(ap, int));
}

void ft_display(va_list ap, t_param *prm)
{
	char s;

	s = prm->type;
	if (s == 'd' || s == 'i' || s == 'u' || s == 'x' || s == 'X' || s == 'o')
		ft_display_int(ap, prm);
	else if (s == 'f')
		ft_display_float(ap, prm);
	else if (s == 'c')
		ft_display_char(ap);
	else if (s == 's' || s == 'S')
		ft_display_str(ap);
	else if (s == '%')
		ft_putchar('%');
}
