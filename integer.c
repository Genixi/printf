/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:32:20 by equiana           #+#    #+#             */
/*   Updated: 2019/11/12 17:35:15 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
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
	int width;
	char* str;
	char* nbr_str;
    
	nbr_str = NULL;
	size = get_num_len(n);
	sign = (n < 0) ? 1 : 0;
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
			char_fill(str, width + 1, ' ');
		else
			char_fill(str, width + 1, '0');
//		printf("str: %s\n", str);
		nbr_str = (sign == 1) ? ft_itoa_base(-n, 10) : ft_itoa_base(n, 10);
		if (sign)
			str[0] = '-';
//		printf("nbr_str: %s\n", nbr_str);
		//обработать если itoa вернет  NULL
		i = width + sign - size - 1;
//		printf("i: %d\n", i);
		j = 0;
		while (i + j < width + 1)
		{
			str[i + j] = nbr_str[j];
			j++;
		}
		//чистить за собой nbr_str, т.к. он не нужен
	}
	else
		str = ft_itoa_base(n, 10);
	ft_putstr(str);
	free(str);
	free(nbr_str);
}
