/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:02:44 by equiana           #+#    #+#             */
/*   Updated: 2019/11/15 20:20:37 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <stdlib.h>
#include <stdio.h>
void ft_putnbr_hex(unsigned int n, t_param *prm, int cap)
{
    int size;
    int i;
    int j;
    int width;
    char* str;
    char* nbr_str;
    
	nbr_str = ft_itoa_base_u(n, 16, cap);
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
            char_fill(str, width, ' ');
        else
			char_fill(str, width, '0');
		if (prm->width > prm->precision && prm->precision > size)
			char_fill(str + prm->width - prm->precision, prm->precision, '0'); 
		str[width] = '\0';
        //!!!обработать если itoa вернет  NULL
        i = width - size - 1;
		j = 0;
		while (i + j < width + 1)
        {
            str[i + j] = nbr_str[j];
            j++;
        }
    }
    else
		str = ft_itoa_base_u(n, 16, cap);
    ft_putstr(str);
//!!!почему то не фришиться сразу 2 указателя - разобраться!!
	free(str);
//	free(nbr_str);
}
