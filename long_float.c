/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:41:15 by equiana           #+#    #+#             */
/*   Updated: 2019/11/18 17:22:05 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
static int    get_base(long double n, int *base_size)
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

void ft_putnbr_lf(long double n, t_param *prm)
{
    int sign;
    int space;
	unsigned long int_part;
    long fraction_part;
    long double tmp;
    int precision;
    int dot;
    int base;
    int base_int;
    int base_fraction;
    int count;
    char c_fill;
	char *res;
    char *str;
    int i;
    int j;
    
    i = 0;
    j = 0;
    count = 0;
    str = NULL;
    res = NULL;
    c_fill = (prm->flag == '0' || prm->flag_2 == '0') ? '0' : ' ';
	space = (prm->flag == ' ' || prm->flag_2 == ' ') ? 1 : 0;
	sign = (n < 0) ? 1 : 0;
    if (sign)
        n = -n;
    int_part = (unsigned long)n;
    precision = (prm->precision == -1) ? 6 : prm->precision;
    tmp = n - (long double)int_part;
//  printf(" !!int_part: %ld, fraction_tmp: %Lf!! ", int_part, tmp);
    dot = (tmp != 0 && precision > 0) ? 1 : 0;
    if (tmp)
    {
        while (i < precision)
        {
            tmp *= 10;
            if (tmp < 1.0)
                count++;
            i++;
        }
    }
    fraction_part = (long)tmp;
//  printf(" !!fraction_tmp: %Lf!! ", tmp);
//  printf(" !!fraction: %lu!! \n", fraction_part);
    
    //    rounding integer part
    if (!dot && n - (long double)int_part >= 0.5)
        int_part += 1;
    
    //    rounding fraction part
    if (tmp - (long double)fraction_part >= 0.5)
        fraction_part += 1;
    
    //    printf(" !!dot: %d, intenger part: %d!! ", dot, int_part);
    
    base_int = 0;
    base_fraction = 0;
    base = get_base(n, &base_int) / 10;
    if (fraction_part)
        base += get_base(fraction_part, &base_fraction) / 10;
    base_int = (base_int == 0) ? 1 : base_int;
    
    i = 0;
    //    printf(" !! prm->width: %d, width: %d\n", prm->width, base_int + dot + precision + sign);
    if (prm->width > base_int + dot + precision + sign)
    {
        while (i++ < prm->width - (base_int + dot + precision + sign))
			if (prm->flag != '-' && prm->flag_2 != '-')
				ft_putchar(c_fill);
        if (space)
			ft_putchar(' ');
		if (sign)
            ft_putchar('-');
		else if (prm->flag == '+' || prm->flag_2 == '+')
			ft_putchar('+');
        ft_putstr(ft_itoa_base_ul(int_part, 10, 0));
        if (precision > 0 && fraction_part)
        {
            ft_putchar('.');
            ft_putstr(ft_itoa_base_ul(fraction_part, 10 ,0));
        }
    }
    else
    {
        if (space)
			ft_putchar(' ');
		if (sign)
            ft_putchar('-');
		else if(prm->flag == '+' || prm->flag_2 == '+')
			ft_putchar('+');
        ft_putstr(ft_itoa_base_ul(int_part, 10, 0));
        if (precision > 0 && fraction_part)
        {
            ft_putchar('.');
            while(count--)
                ft_putchar('0');
            ft_putstr(ft_itoa_base_ul(fraction_part, 10, 0));
        }
    }
    //!!!! почему то при очисте памяти происходит некорректный вывод - разобраться!!
    //    free(res);
    //    ft_putstr(res);
}
