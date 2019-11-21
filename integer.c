/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:32:20 by equiana           #+#    #+#             */
/*   Updated: 2019/11/21 21:53:01 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int get_num_len(long int n)
{
	int size;

	size = 0;
	if (n < 0)
		n = n * -1;
	while (n)
	{
		if (n /= 10)
			size++;
	}
	size++;
	return (size);
}

void char_fill(char *str, int start, int end, char c, int eof)
{
	int i;

	i = start;
	while (i < end)
		str[i++] = c;
	if (eof)
		str[end - 1] = '\0';
//	str[i] = '\0';
}

void    ft_putnbr_i(int n, t_param *prm)
{
	int	size;
	int i;
    int j;
	int sign;
	int space;
	int width;
	int head;
	char c_fill;
	char* str;
	char* nbr_str;
    
	nbr_str = NULL;
	size = get_num_len(n);
	c_fill = (prm->flag == '0' || prm->flag_2 == '0') ? '0' : ' ';
	space = (prm->flag == ' ' || prm->flag_2 == ' ') ? 1 : 0;
	head = (prm->flag == '-' || prm->flag_2 == '-' || prm->flag_3 == '-') ? 1 : 0;
	sign = (n < 0) ? 1 : 0;
	
	if (prm->flag == '+' || prm->flag_2 == '+')
		sign = 1;
	
	width = (prm->width >= prm->precision) ? prm->width : prm->precision;
//	printf("flag: %c, flag_2: %c\n", prm->flag, prm->flag_2);
//	printf("check width: %d, sign: %d, size: %d, c_fill: %c\n", width, sign, size, c_fill);	
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
//		printf("width_-1: %zu", ft_strlen(str));
//
		
		char_fill(str, 0, width + 1, ' ', 1);
//		if (prm->width >= prm->precision && prm->precision <= size)
//			char_fill(str, 0, width + 1, '0', 1);
//		else if (prm->width >= prm->precision && prm->precision > size)
//			char_fill(str, prm->width - prm->precision, prm->width + 1, '0', 1);
//		else 
//			char_fill(str, 0, width + 1, '0', 1);
		if (prm->width > prm->precision && prm->precision > size && !head)
			char_fill(str, prm->width - prm->precision, prm->width + 1, '0', 1);
		else if (prm->width > prm->precision && prm->precision > size && head)
			char_fill(str, 0, prm->precision, '0', 0);
		else if (prm->width > prm->precision && prm->precision == -1 && c_fill == '0')
			char_fill(str, 0, width + 1, '0', 1);
		else if (prm->width < prm->precision && prm->precision > size)
			char_fill(str, 0, width + 1, '0', 1);

//		printf("str: %s\n", str);
//		printf("width_0: %zu", ft_strlen(str));
		nbr_str = (n < 0) ? ft_itoa_base(-n, 10) : ft_itoa_base(n, 10);
		if (head && sign)			
			str[0] = (n < 0) ? '-' : '+';
		else if (head && space)
			str[0] = (n < 0) ? '-' : ' ';
		else if (!head && sign && prm->width < prm->precision)
			str[0] = (n < 0) ? '-' : '+';
		else if (!head && sign && prm->width >= prm->precision && prm->precision <= size)
		{
			if (c_fill == '0' && prm->precision == -1)
				str[0] = (n < 0) ? '-' : '+';
			else
				str[width + sign - size - 2] = (n < 0) ? '-' : '+';
//			str[width + sign - size - 2] = (n < 0) ? '-' : '+';
		}
//			str[width + sign - size - 2] = (n < 0) ? '-' : '+';
		else if (!head && sign && prm->width >= prm->precision && prm->precision > size)
		{
//			if (c_fill == '0')
//				str[0] = (n < 0) ? '-' : '+';
//			else
//				str[prm->width - prm->precision - 1] = (n < 0) ? '-' : '+';
			str[prm->width - prm->precision - 1] = (n < 0) ? '-' : '+';
		}
//			str[prm->width - prm->precision - 1] = (n < 0) ? '-' : '+';
//		printf("nbr_str: %s\n", nbr_str);
		//обработать если itoa вернет  NULL
//		printf(" width_mid: %zu ", ft_strlen(str));
		i = (str[0] == '-' || str[0] == '+') ? 1 : 0;
		if (space && n >= 0)
		{
			i = 1;
			str[0] = ' ';
		}
		if (!head)
			i = width + sign - size - 1 * sign;
		else if (prm->precision > size && head)
			i = prm->precision - size + sign;
		j = 0;

//		printf("nbr: %s", nbr_str);

		while (nbr_str[j] && str[i + j])
		{
			str[i + j] = nbr_str[j];
			j++;
		}
//		printf("width_end: %zu", ft_strlen(str));
//		if (space && !sign &&)
//			ft_putchar(' ');
		//чистить за собой nbr_str, т.к. он не нужен
		ft_putstr(str);
//		printf("%s", str);
		free(str);
//		free(nbr_str);
	}
	else
	{
		if (space && !sign)
			ft_putchar(' ');
		if ((prm->flag == '+' || prm->flag_2 == '+') && n >= 0)
			ft_putchar('+');
		ft_putstr(ft_itoa_base(n, 10));
	}
}
