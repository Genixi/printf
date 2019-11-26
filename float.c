/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:59:41 by equiana           #+#    #+#             */
/*   Updated: 2019/11/26 21:13:01 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
int decimal_count(double n)
{
	int i;
	double long decimal;
	long tmp;

	i = 0;
	tmp = 0;
	if (n < 0)
		n *= -1;
	decimal = n - (long)n;
//	printf("decimal: %Lf ", decimal);
	if (decimal)
		while(tmp < 1)
		{
			i++;
//			printf("tmp: %ld, decimal: %LF:, i: %d\n", tmp, decimal, i);
	   		decimal *= 10;
			tmp = (long)decimal;
		}
	else
		return (0);

//	printf("\ni: %d\n", i);
	return (i);
}

void ft_putnbr_f(double n, t_param *prm)
{
    double long decimal;
    t_nbr tmp;
    char	c_fill;
	int i;
	int count;
	int sign;
	int dot;
	int size;
    int precision;
	char *str;
   
//	printf("case0");

    sign = (n < 0) ? 1 : 0;
    n = (n < 0) ? (n *= -1) : n;
	count = decimal_count(n);
    precision = (prm->precision == -1) ? 6 : prm->precision;
    decimal = (n - (long)n) * ft_iterative_power(10, precision + 1);
    decimal = ((long)decimal % 10 > 4) ? (decimal) / 10 + 1 : decimal / 10;
    tmp.n = (long)n + (long)(decimal / ft_iterative_power(10, precision));
    tmp.decimal = (long)decimal % (long)ft_iterative_power(10, precision);
    tmp.size = get_num_len(tmp.n);
	dot = (tmp.decimal != 0 && precision > 0) ? 1 : 0;   

	c_fill = (prm->null) ? '0' : ' ';
	
//	printf("\nsign: %d, int part: %lu, dec part: %ld\n", sign, tmp.n, tmp.decimal);
	
	i = 0;
	if (prm->width > tmp.size + dot + precision + sign + prm->space)
	{
		while (i++ < prm->width - (tmp.size + dot + precision + sign))
			if (!prm->head)
				ft_putchar(c_fill);
		if (prm->space)
		   ft_putchar(' ');
		if (sign)
			ft_putchar('-');
		else if (prm->plus)
			ft_putchar('+');
		ft_putstr(ft_itoa_base_ul(tmp.n, 10, 0));
		if (precision > 0 && tmp.decimal)
		{
			ft_putchar('.');
			ft_putstr(ft_itoa_base_li(tmp.decimal, 10 ,0));
		}
	}
	else
	{
		if (prm->space)
			ft_putchar(' ');
		if (sign)
			ft_putchar('-');
		else if (prm->plus)
			ft_putchar('+');
		ft_putstr(ft_itoa_base_ul(tmp.n, 10, 0));
		size = get_num_len(tmp.decimal);
//		printf("count: %d ", count);
		if (precision == 6 && (count == 0 || count > 7))
		{
//			printf("count = %d", count);
			ft_putstr(".000000");
		}
		else if (precision > 0)
		{
			ft_putchar('.');
			count --;
			if (count == 6)
			{
				ft_putstr("00000");
				precision -= 5;
			}
			else
			{
				while (count && precision)
				{
//				printf("count: %d", count);
					ft_putchar('0');
					precision--;
					count--;
				}
			}
			str = ft_itoa_base_li(tmp.decimal, 10, 0);
			i = 0;
			while (precision && str[i])
			{
				ft_putchar(str[i++]);
				precision--;
			}
			while (precision)
			{
				ft_putchar('0');
				precision--;
			}			
		}
	}
//	free(res);
//	ft_putstr(res);
}
