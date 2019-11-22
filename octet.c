/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octet.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:06:48 by equiana           #+#    #+#             */
/*   Updated: 2019/11/22 14:19:12 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>
#include <stdio.h>
void ft_putnbr_oct(unsigned int n, t_param *prm)
{
    int size;
    int space;
	int i;
    int j;
    int width;
    char c_fill;
	char* str;
    char* nbr_str;
    
    nbr_str = ft_itoa_base_u(n, 8, 0);
    c_fill = (prm->flag == '0' || prm->flag_2 == '0') ? '0' : ' ';
	space = (prm->flag == ' ' || prm->flag_2 == ' ') ? 1 : 0;
	size = ft_strlen(nbr_str);
    width = (prm->width >= prm->precision) ? prm->width : prm->precision;
	if (width > size)
    {
        if (prm->precision > prm->width)
		{
            if (!(str = (char*)malloc(sizeof(char) * (width + 1))))
                ft_error(1);
		}
        else
		{
            if (!(str = (char*)malloc(sizeof(char) * (width + 1))))
                ft_error(1);
		}
        width++;
		if (prm->width >= prm->precision)
            char_fill(str, 0, width, c_fill, 1);
        else
            char_fill(str, 0, width, '0', 1);
        if (prm->width > prm->precision && prm->precision > size)
			char_fill(str, prm->width - prm->precision, prm->width, '0', 1);
		str[width] = '\0';
		//обработать если itoa вернет  NULL
        i = 0;
		if (prm->flag != '-' && prm->flag_2 != '-')
			i = width - size - 1;
		j = 0;
        while (i + j < width + 1)
        {
            str[i + j] = nbr_str[j];
            j++;
        }
    }
    else
        str = ft_itoa_base_u(n, 8, 0);
    if (space)
		ft_putchar(' ');
	ft_putstr(str);
//!!!почему то не фришиться сразу 2 указателя - разобраться!!
	free(str);
//	free(nbr_str);
}
