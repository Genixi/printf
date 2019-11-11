/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:59:41 by equiana           #+#    #+#             */
/*   Updated: 2019/11/11 20:53:55 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
static int    get_base(double n, int *base_size)
{
    int base;
    
    base = 1;
    while ((long)(n))
    {
        if (n /= 10)
			base *= 10;
		(*base_size)++;
    }
    return (base);
}

void    ft_putnbr_f(double n, t_param *prm)
{
	int sign;
    int base;
	int base_size;
    int tmp;
	int width;
    char *res;
    char *str;
	int i;
	int j;
    
	i = 0;
	j = 0;
	str = NULL;
	res = NULL;
	base_size = 0;
    base = get_base(n, &base_size) / 10;
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	base_size = (base_size == 0) ? 1 : base_size;
	width = prm->precision;
	if (!(res = (char*)malloc(sizeof(char) * (base_size + width + sign + 1))))
        ft_error(1);
    res[base + width + sign] = '\0';
    if (sign)
		res[i++] = '-';
	if (base)
		while ((long)n != 0)
    	{
        	res[i] = (char)(n / base + '0');
        	n = n - (int)(n / base) * base;
			base = base / 10;
        	i++;
    	}
	else
		res[i++] = '0';
	res[i] = '.';
    i++;
    n = n * 10;
    while (i < base_size +  width + sign + 1)
    {
		tmp = (int)n;
		res[i] = (char)(tmp + '0');
		n = (n - tmp) * 10;	
		i++;
    }
/*	if (prm->width > base_size + width + sign)
	{
//		printf("case 1\n");
		if (!(str= (char*)malloc(sizeof(char) * (prm->width + 1))))
			ft_error(1);
		char_fill(str, prm->width + 1, ' ');
		i = prm->width - (base_size + width + sign) - 1;
		j = 0;
		while (j < base_size + width + sign + 1)
		{
			str[i + j] = res[j];
			j++;
		}
		ft_putstr(str);
		free(str);
	}
	else
		ft_putstr(res);
	free(res);
*/	ft_putstr(res);
}

void	ft_display_float(va_list ap, t_param *prm)
{
	double n;

	n = (double)va_arg(ap, double);
	ft_putnbr_f(n, prm);
}
