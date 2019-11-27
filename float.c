/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:59:41 by equiana           #+#    #+#             */
/*   Updated: 2019/11/27 18:09:36 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
int decimal_count(double n)
{
	int i;
	double long decimal;

	i = 0;
	if (n < 0)
		n *= -1;
	decimal = n - (long)n;
//	printf("\ndecimal: %Lf\n", decimal);
	if (decimal)
		while(decimal < 1.0)
		{
			i++;
	   		decimal *= 10;
//			printf("decimal: %LF:, <1.0?: %d, i: %d\n", decimal, (decimal < 1.0), i);
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
//  printf("\nbefore: %f\n", n - (long)n);
	decimal = (n - (long)n) * ft_power(10, precision + 1);
// 	printf("after: %Lf\n", decimal);
	decimal = ((long)decimal % 10 > 4) ? (decimal) / 10 + 1 : decimal / 10;
//  printf("decimal_1: %Lf\n", decimal);
	tmp.n = (long)n + (long)(decimal / ft_power(10, precision));
    tmp.decimal = (long)decimal % (long)ft_power(10, precision);
//  printf("\ntmp.decimal: %ld\n", tmp.decimal);
	tmp.size = get_num_len(tmp.n);
	dot = (tmp.decimal != 0 && precision >= 0) ? 1 : 0;   

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
		if (precision >= 0 && tmp.decimal)
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
//			printf("count1 = %d", count);
			ft_putstr(".000000");
		}
		else if (precision >= 0)
		{
			ft_putchar('.');
			count --;
			if (count == precision)
				while (count > 1 && precision > 1)
				{
//					printf("case2");
//					printf("count2: %d, precision: %d\n", count, precision);
					ft_putchar('0');
					precision--;
					count--;
				}
			else
			{
//				printf("\ncount: %d, precision: %d\n", count, precision);
				while(count && precision)
				{
//					printf("case1");
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
