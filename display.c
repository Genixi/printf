/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:08:23 by equiana           #+#    #+#             */
/*   Updated: 2019/11/26 17:36:14 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
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
	if (str)
		ft_put_str(str, prm);
	else
	{
		ft_put_str_e(str, prm);
	}
}

void ft_display_int(va_list ap, t_param *prm)
{
	char s;

	s = prm->type;
	if (s == 'd' || s == 'i')
		if (prm->mod == 'l' && prm->mod_2 == 'Z')
			ft_putnbr_li((long int)va_arg(ap, long int), prm);
		else if (prm->mod == 'l' && prm->mod_2 == 'l')
			ft_putnbr_li((unsigned long long int)va_arg(ap, unsigned long long int), prm);
		else if (prm->mod == 'h' && prm->mod_2 == 'Z')
			ft_putnbr_hi((short int)va_arg(ap, int), prm);
		else if (prm->mod == 'h' && prm->mod_2 == 'h')
			ft_putnbr_hhi((signed char)va_arg(ap, int), prm);
		else
			ft_putnbr_i(va_arg(ap, int), prm);
	else if (s == 'u')
		if (prm->mod == 'l' && prm->mod_2 == 'Z')
			ft_putnbr_lu((long int)va_arg(ap, long int), prm);
		else if (prm->mod == 'l' && prm->mod_2 == 'l')
			ft_putnbr_lu((unsigned long long int)va_arg(ap, unsigned long long int), prm);
		else if (prm->mod == 'h' && prm->mod_2 == 'Z')
			ft_putnbr_hu((unsigned short int)va_arg(ap, int), prm);
		else if (prm->mod == 'h' && prm->mod_2 == 'h')
			ft_putnbr_hhu((unsigned char)va_arg(ap, int), prm);
		else
			ft_putnbr_u((unsigned int)va_arg(ap, unsigned int), prm);
	else if (s == 'x')
		if (prm->mod == 'l' && prm->mod_2 == 'Z')
			ft_putnbr_lx((unsigned long int)va_arg(ap, unsigned long int), prm, 0);
		else if (prm->mod == 'l' && prm->mod_2 == 'l')
			ft_putnbr_lx((unsigned long long int)va_arg(ap, unsigned long long int), prm, 0);
		else if (prm->mod == 'h' && prm->mod_2 == 'Z')
			ft_putnbr_hx((unsigned short int)va_arg(ap, int), prm, 0);
		else if (prm->mod == 'h' && prm->mod_2 == 'h')
			ft_putnbr_hhx((unsigned char)va_arg(ap, int), prm, 0);
		else
			ft_putnbr_hex((unsigned int)va_arg(ap, unsigned int), prm, 0);
	else if (s == 'X')
		if (prm->mod == 'l' && prm->mod_2 == 'Z')
			ft_putnbr_lx((unsigned long int)va_arg(ap, unsigned long int), prm, 1);
		else if (prm->mod == 'l' && prm->mod_2 == 'l')
			ft_putnbr_lx((unsigned long long int)va_arg(ap, unsigned long long int), prm, 1);
		else if (prm->mod == 'h' && prm->mod_2 == 'Z')
			ft_putnbr_hx((unsigned short int)va_arg(ap, int), prm, 1);
		else if (prm->mod == 'h' && prm->mod_2 == 'h')
			ft_putnbr_hhx((unsigned char)va_arg(ap, int), prm, 1);
		else
			ft_putnbr_hex((unsigned int)va_arg(ap, unsigned int), prm, 1);
	else if (s == 'o')
		if (prm->mod == 'l' && prm->mod_2 == 'Z')
			ft_putnbr_lo((unsigned long int)va_arg(ap, unsigned long int), prm);
		else if (prm->mod == 'l' && prm->mod_2 == 'l')
			ft_putnbr_lo((unsigned long long int)va_arg(ap, unsigned long long int), prm);
		else if (prm->mod == 'h' && prm->mod_2 == 'Z')
			ft_putnbr_ho((unsigned short int)va_arg(ap, int), prm);
		else if (prm->mod == 'h' && prm->mod_2 == 'h')
			ft_putnbr_hho((unsigned char)va_arg(ap, int), prm);
		else
			ft_putnbr_oct((unsigned int)va_arg(ap, unsigned int), prm);
	else if( s == 'p')
		ft_putnbr_ptr((unsigned long long int)va_arg(ap, unsigned long long int), prm, 0);
}

void	ft_display_float(va_list ap, t_param *prm)
{
	if (prm->mod == 'L')
	{
		ft_putnbr_lf((double long)va_arg(ap, double long), prm);
	}
	else
		ft_putnbr_f((double)va_arg(ap, double), prm);
}

void ft_display(va_list ap, t_param *prm)
{
	char s;
	
	s = prm->type;
	if (s == '%')
		ft_put_char('%', prm);
	if (s == 'd' || s == 'i' || s == 'u' || s == 'x' || s == 'X' || s == 'o' || s == 'p')
		ft_display_int(ap, prm);
	else if (s == 'f')
		ft_display_float(ap, prm);
	else if (s == 'c')
		ft_display_char(ap, prm);
	else if (s == 's' || s == 'S')
		ft_display_str(ap, prm);
}
