/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:59:41 by equiana           #+#    #+#             */
/*   Updated: 2019/11/09 13:53:50 by equiana          ###   ########.fr       */
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

void    ft_display_float(va_list ap, t_param *prm)
{
    double n;
	int sign;
    int base;
	int base_size;
    int tmp;
    char *res;
    int i;
    
	n = va_arg(ap, double);
	i = 0;
	base_size = 0;
    base = get_base(n, &base_size) / 10;
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	base_size = (base_size == 0) ? 1 : base_size;
	if (!(res = (char*)malloc(sizeof(char) * (base_size + prm->precision + sign + 1))))
        ft_error(1);
    res[base + prm->precision + sign] = '\0';
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
//	printf("length:%d = base_size:%d + precision:%d + sign:%d + 1\n", base_size + prm->precision + sign + 1, base_size, prm->precision, sign); 
    while (i < base_size + prm->precision + sign + 1)
    {
		tmp = (int)n;
		res[i] = (char)(tmp + '0');
		n = (n - tmp) * 10;	
		i++;
    }
	ft_putstr(res);
}
