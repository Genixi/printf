/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:32:20 by equiana           #+#    #+#             */
/*   Updated: 2019/11/09 16:57:22 by equiana          ###   ########.fr       */
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
	int width;
	char* str;
	char* nbr_str;
    
	size = get_num_len(n);
	width = (prm->width >= prm->precision) ? prm->width : prm->precision;
	printf(" check width = %d ", width);	
	if (width > size)
	{
		if (!(str = (char*)malloc(sizeof(char) * (width + 1))))
			ft_error(1);
		if (width > prm->precision)
			char_fill(str, prm->width + 1, ' ');
		else
			char_fill(str, prm->width + 1, '0');
		nbr_str = ft_itoa_base(n, 10);
//		printf("nbr_str: %s\n", nbr_str);
		//обработать если itoa вернет  NULL
		i = width - size - 1;
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
}
