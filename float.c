/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:59:41 by equiana           #+#    #+#             */
/*   Updated: 2019/11/29 18:11:01 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int decimal_count(double n)
{
	int i;
	double long decimal;
//	double decimal;

	i = 0;
	if (n < 0)
		n *= -1; 
	decimal = n - (unsigned long)n;
//	printf("\ndecimal Lf: %.20Lf\n", decimal);
//	printf("\ndecimal f: %.20f\n", decimal);
	if (decimal)
		while(decimal < 1)
		{
			i++;
	   		decimal *= 10;
//			printf("compare: %d\n", decimal == 0.000001);
//			printf("decimal: %.20LF, i: %d\n", decimal, i);
//			printf("decimal * 10 < 5 ?: %d\n", decimal * 10 < 5);
		}
	else
		return (0);

//	printf("\ni: %d\n", i);
	if (i == 7 && (int)decimal == 9)
		i -= 1;
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
   

    sign = (n < 0) ? 1 : 0;
    n = (n < 0) ? (n *= -1) : n;
	count = decimal_count(n);
    precision = (prm->precision == -1) ? 6 : prm->precision;
	decimal = (n - (long)n) * ft_power(10, precision + 1);
	decimal = ((long)decimal % 10 > 4) ? (decimal) / 10 + 1 : decimal / 10;
	tmp.n = (long)n + (long)(decimal / ft_power(10, precision));
    tmp.decimal = (long)decimal % (long)ft_power(10, precision);
	tmp.size = get_num_len(tmp.n);
	dot = (tmp.decimal != 0 && precision >= 0) ? 1 : 0;   

	c_fill = (prm->null && !prm->head) ? '0' : ' ';
	
//	printf("\ntmp.size: %d, sign: %d, int part: %lu, dec part: %ld\n", tmp.size, sign, tmp.n, tmp.decimal);
//	printf("\nnumber: %.20f\n", n);
//	printf("decimal: %.20Lf\n", decimal);	
	if (prm->plus)
		prm->space = 0;
	i = 0;
//	printf("res: %d\n", tmp.size + dot * ((precision == 0) ? 0 : 1) + precision + sign + prm->space);
	if (prm->width > tmp.size + dot * ((precision == 0) ? 0 : 1) + precision + (sign || prm->space))
	{
		if (prm->space && c_fill == '0' && !(sign || prm->plus))
		{
			i++;
			ft_putchar(' ');
			prm->space = 0;
		}
		if ((sign || prm->plus) && (prm->head || prm->null))
		{
			i++;
			(sign) ? ft_putchar('-') : ft_putchar('+');
			sign = 0;
			prm->plus = 0;
			prm->space = 0;
		}
		if (!prm->head)
		{
//			printf("aa");
			while (i++ < prm->width - (tmp.size  + dot* ((precision == 0) ? 0 : 1) + precision + (sign || prm->plus)))
				ft_putchar(c_fill);
			if (prm->space && !(c_fill == ' ' && i > 2) && !(sign || prm->plus))
			{
//				printf("ss");
				i++;
				ft_putchar(' ');
			}
			else if ((sign || prm->plus) && i++)
				(sign) ? ft_putchar('-') : ft_putchar('+');
			ft_putstr(ft_itoa_base_ul(tmp.n, 10, 0));
			if (precision >= 0 && tmp.decimal)
			{
//				printf("case1");
				ft_putchar('.');
				ft_putstr(ft_itoa_base_li(tmp.decimal, 10 ,0));
//			ft_put_decimal(tmp.decimal);
//			printf("%ld", tmp.decimal);
			}
		}
		else
		{
//			printf("i start: %d\n", i);
			if (prm->space)
			{
				i++;
				ft_putchar(' ');
			}
			else if (prm->plus)
			{
				i++;
				ft_putchar('+');
			}
//			while (i++ < prm->width - (tmp.size  + dot* ((precision == 0) ? 0 : 1) + precision))
//				ft_putchar(c_fill);
			ft_putstr(ft_itoa_base_ul(tmp.n, 10, 0));
			i += ft_strlen(ft_itoa_base_ul(tmp.n, 10, 0));
//			printf("i middle: %d\n", i);
			if (precision >= 0 && tmp.decimal)
			{
//				printf("case2");
				ft_putchar('.');
				ft_putstr(ft_itoa_base_li(tmp.decimal, 10 ,0));
				i += ft_strlen(ft_itoa_base_li(tmp.decimal, 10 ,0)) + 1;
			}
			else if (precision == 0 && prm->hash)
			{
				i++;
				ft_putchar('.');
			}
//			printf("i end: %d\n", i);
			while (i++ < prm->width)
				ft_putchar(c_fill);
		}
	}
	else
	{
		if (prm->space && !sign)
			ft_putchar(' ');
		if (sign)
		{
			ft_putchar('-');
			sign = 0;
		}
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
//			printf("case3");
			if (!(precision == 0 && !prm->hash))
				ft_putchar('.');
			count --;
			if (count == precision)
				while (count > 1 && precision > 1)
				{
					ft_putchar('0');
					precision--;
					count--;
				}
			else
			{
				while(count && precision)
				{
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
