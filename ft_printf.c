/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:57:54 by equiana           #+#    #+#             */
/*   Updated: 2019/11/07 00:21:02 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

int ft_pars(char *str, va_list ap, t_param *prm)
{
	int d;
	char c;
	char *s;
	unsigned int u;
	double f;

	if (*str == 'd' || *str == 'i')
	{
		prm->spec = 'd';
		d = va_arg(ap, int);
		ft_putnbr(d);
	}
	else if (*str == 'u')
	{
		prm->spec = 'u';
		u = va_arg(ap, unsigned int);
		ft_putnbr_u(u);
	}
	else if (*str == 'f')
	{
		prm->spec = 'f';
		prm->precision = 10;
		f = va_arg(ap, double);
		ft_putnbr_f(f, prm);
	}
	else if (*str == 'c')
	{
		prm->spec = 'c';
		c = (char)va_arg(ap, int);
		write(1, &c, 1);
	}
	else if (*str == 's' || *str == 'S')
	{
		prm->spec = 's';
		s = va_arg(ap, char*);
		ft_putstr(s);
	}
    return (0);
}

int ft_printf(const char *restrict format, ...)
{
    char *str;
    int res;
	t_param prm;

    va_list ap;
    va_start(ap, format);
    res = 0;
    str = (char*)format;
    while (*str)
    {
        if (*str == '%')
        {
            str++;
            res = ft_pars(str, ap, &prm);
        }
        else
            write(1, str, 1);
        str++;
    }

    va_end(ap);
    return (res);
}


