/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:48:26 by equiana           #+#    #+#             */
/*   Updated: 2019/11/21 13:00:36 by equiana          ###   ########.fr       */
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
    str = NULL;
	c_fill = (prm->flag == '0' || prm->flag_2 == '0') ? '0' : ' ';
	space = (prm->flag == ' ' || prm->flag_2 == ' ') ? 1 : 0;
	size = ft_strlen(nbr_str);
    width = (prm->width >= prm->precision) ? prm->width : prm->precision;
//	printf("width: %d ", width);
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
		{
			str[width - size - 3] = '0';
			str[width - size - 2] = 'x';
			i = width - size - 1;
		}
		else
		{
			str[0] = '0';
			str[1] = 'x';
			i = 2;
		}
		j = 0;
		while (nbr_str[j] && str[i + j])
        {
            str[i + j] = nbr_str[j];
            j++;
        }
		if (space)
			ft_putchar(' ');
		ft_putstr(str);
		free(str);
    }
    else
	{
		if (space)
			ft_putchar(' ');
		ft_putstr("0x");
		ft_putstr(ft_itoa_base_ul(n, 16, cap));
	}
}

