/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:59:41 by equiana           #+#    #+#             */
/*   Updated: 2019/11/16 17:20:56 by equiana          ###   ########.fr       */
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

void ft_putnbr_f(double n, t_param *prm)
{
	int sign;
    int int_float;
	int fraction;
	int precision;
	int dot;
	int base;
	int base_size;
    int tmp;
    char *res;
    char *str;
	int i;
	int j;
    
	i = 0;
	j = 0;
	str = NULL;
	res = NULL;
	sign = (n < 0) ? 1 : 0;
	int_float = (long)n;
	precision = (prm->precision == -1) ? 6 : prm->precision;
	fraction = int_float - n;
	dot = (fraction == 0) ? 0 : 1;
	if (fraction)
		while (i < j)
		{
			fraction *= 10;
			i++;
		}
	
	
	base_size_int = 0;
	base = get_base(n, &base_size_int) / 10;
	base_size_fraction = 0;
	if (fraction)
		base += get_base_fraction(fraction, &base_size_fraction) / 10;
	base_size_int = (base_size_int == 0) ? 1 : base_size_int;

	
	if (prm->width > base_size_int + dot + base_ prm->precision + sign)
	{
//		printf("case 1\n");
		if (!(str= (char*)malloc(sizeof(char) * (prm->width + 1))))
			ft_error(1);
		char_fill(str, prm->width + 1, ' ');
		i = prm->width - (base_size + prm->precision + sign) - 1;
		j = 0;
		while (i + j < prm->width + 1)
		{
			str[i + j] = res[j];
			j++;
		}
		str[prm->width] = '\0';
//		printf(" str: %s\n", str);
		ft_putstr(str);
//		free(str);
	}
	else
		ft_putstr(res);
//!!!! почему то при очисте памяти происходит некорректный вывод - разобраться!!
//	free(res);
//	ft_putstr(res);
}
