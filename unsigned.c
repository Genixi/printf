/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:15:40 by equiana           #+#    #+#             */
/*   Updated: 2019/11/12 20:30:01 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <stdio.h>

void    ft_putnbr_u(unsigned int n, t_param *prm)
{
	int size;
	int i;
    int j;
	int width;
	char* str;
	char* nbr_str;

	size = get_num_len(n);
	nbr_str = NULL;
	width = (prm->width >= prm->precision) ? prm->width : prm->precision;
	if (width > size)
	{
		if (!(str = (char*)malloc(sizeof(char) * (width + 1))))
			ft_error(1);
		if (prm->width >= prm->precision)
			char_fill(str, width + 1, ' ');
		else
			char_fill(str, width + 1, '0');
		nbr_str = ft_itoa_base_u(n, 10, 0);
		//обработать если itoa вернет  NULL
		i = width - size - 1;
		j = 0;
		while (i + j < width + 1)
		{
			str[i + j] = nbr_str[j];
			j++;
		}		
	}
	else
		str = ft_itoa_base_u(n, 10, 0);
	ft_putstr(str);
	free(str);
	free(nbr_str);
}

