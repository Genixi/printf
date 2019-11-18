/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:48:26 by equiana           #+#    #+#             */
/*   Updated: 2019/11/18 17:41:43 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>
#include <stdio.h>
void ft_putnbr_ptr(unsigned long long int n, t_param *prm, int cap)
{
    int size;
    int space;
	int i;
    int j;
    int width;
    char c_fill;
	char* str;
    char* nbr_str;
    
	nbr_str = ft_itoa_base_ul(n, 16, cap);
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
            char_fill(str, width, c_fill);
        else
            char_fill(str, width, '0');
		if (prm->width > prm->precision && prm->precision > size)
			char_fill(str + prm->width - prm->precision, prm->precision, '0');
		str[width] = '\0';
        //!!!обработать если itoa вернет  NULL
        i = 0;
		if (prm->flag != '-' && prm->flag_2 != '-')
			i = width - size - 1;
		j = 0;
		str[width - size - 3] = '0';
		str[width - size - 2] = 'x';
		while (i + j < width + 1)
        {
            str[i + j] = nbr_str[j];
            j++;
        }
		if (space)
			ft_putchar(' ');
    }
    else
	{
		if (space)
			ft_putchar(' ');
		ft_putstr("0x");
		str = ft_itoa_base_ul(n, 16, cap);
	}
    ft_putstr(str);
//!!!почему то не фришиться сразу 2 указателя - разобраться!!
	free(str);
//	free(nbr_str);
}

