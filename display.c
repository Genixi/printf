/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:08:23 by equiana           #+#    #+#             */
/*   Updated: 2019/11/12 21:10:37 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

void ft_display_char(va_list ap, t_param *prm)
{
	char c;

	c = (char)va_arg(ap, int);
	ft_put_char(c, prm);
}

void ft_display_str(va_list ap, t_param *prm)
{
	char *str;

	str = (char*)va_arg(ap, char*);
	ft_put_str(str, prm);
}

void ft_display_int(va_list ap, t_param *prm)
{
	char s;

	s = prm->type;
	if (s == 'd' || s == 'i')
		if (prm->mod == 'l')
			ft_putnbr_i(va_arg(ap, int), prm);
		else
			ft_putnbr_i(va_arg(ap, int), prm);
	else if (s == 'u')
		ft_putnbr_u((unsigned int)va_arg(ap, unsigned int), prm);
	else if (s == 'x')
		ft_putnbr_hex((unsigned int)va_arg(ap, unsigned int), prm, 0);
	else if (s == 'X')
		ft_putnbr_hex((unsigned int)va_arg(ap, unsigned int), prm, 1);
	else if (s == 'o')
		ft_putnbr_oct((unsigned int)va_arg(ap, unsigned int), prm);
	else if( s == 'p')
		ft_putnbr_ptr((unsigned int)va_arg(ap, unsigned int), prm, 0);
}

void ft_display(va_list ap, t_param *prm)
{
	char s;
	
	s = prm->type;
	if (s == 'd' || s == 'i' || s == 'u' || s == 'x' || s == 'X' || s == 'o' || s == 'p')
		ft_display_int(ap, prm);
	else if (s == 'f')
		ft_display_float(ap, prm);
	else if (s == 'c')
		ft_display_char(ap, prm);
	else if (s == 's' || s == 'S')
		ft_display_str(ap, prm);
	else if (s == '%')
		ft_putchar('%');
}
