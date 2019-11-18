/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:32:20 by equiana           #+#    #+#             */
/*   Updated: 2019/11/18 17:19:52 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int get_num_len(long int n)
{
	int size;

	size = 0;
	if (n < 0)
	{
		n = n * -1;
		size++;
	}
	while (n)
	{
		if (n /= 10)
			size++;
	}
	return (size);
}

void char_fill(char *str, int len, char c)
{
	int i;

	i = 0;
	while (i < len)
		str[i++] = c;
	str[len-1] = '\0';
}

void    ft_putnbr_i(int n, t_param *prm)
{
	int	size;
	int i;
    int j;
	int sign;
	int space;
	int width;
	char c_fill;
	char* str;
	char* nbr_str;
    
	nbr_str = NULL;
	size = get_num_len(n);
	c_fill = (prm->flag == '0' || prm->flag_2 == '0') ? '0' : ' ';
	space = (prm->flag == ' ' || prm->flag_2 == ' ') ? 1 : 0;
	sign = (n < 0) ? 1 : 0;
	
	if (prm->flag == '+')
		sign = 1;
	
	width = (prm->width >= prm->precision) ? prm->width : prm->precision;
//	printf("check width: %d, sign: %d\n", width, sign);	
	if (width > size)
	{
		if (sign && prm->precision > prm->width)
		{
			if (!(str = (char*)malloc(sizeof(char) * (width + sign + 1))))
				ft_error(1);
			width++;
		}
		else
			if (!(str = (char*)malloc(sizeof(char) * (width + 1))))
				ft_error(1);
		if (prm->width >= prm->precision)
			char_fill(str, width + 1, c_fill);
		else
			char_fill(str, width + 1, '0');
		if (prm->width > prm->precision && prm->precision > size)
			char_fill(str + prm->width - prm->precision, prm->precision, '0');
//		printf("str: %s\n", str);
		nbr_str = (sign == 1) ? ft_itoa_base(-n, 10) : ft_itoa_base(n, 10);
		if (sign && prm->width < prm->precision)
			str[0] = (n < 0) ? '-' : '+';
		else if (sign && prm->width >= prm->precision && prm->precision <= size)
			str[width + sign - size - 2] = (n < 0) ? '-' : '+';
		else if (sign && prm->width >= prm->precision && prm->precision > size)
			str[prm->width - prm->precision - 1] = (n < 0) ? '-' : '+';
//		printf("nbr_str: %s\n", nbr_str);
		//обработать если itoa вернет  NULL
		i = 0;
		if (prm->flag != '-' && prm->flag_2 != '-')
			i = width + sign - size - 1;
		j = 0;
		while (nbr_str[j] && i + j < width + 1)
		{
			str[i + j] = nbr_str[j];
			j++;
		}
		if (space)
			ft_putchar(' ');
		//чистить за собой nbr_str, т.к. он не нужен
	}
	else
	{
		if (space)
			ft_putchar(' ');
		if (prm->flag == '+' && n >= 0)
			ft_putchar('+');
		str = ft_itoa_base(n, 10);
	}
	ft_putstr(str);
	free(str);
	free(nbr_str);
}
