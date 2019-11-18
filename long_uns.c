/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_uns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:12:49 by equiana           #+#    #+#             */
/*   Updated: 2019/11/18 17:36:21 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <stdlib.h>

void    ft_putnbr_lu(unsigned long int n, t_param *prm)
{
    int size;
    int space;
	int i;
    int j;
    int width;
    char c_fill;
	char* str;
    char* nbr_str;
    
    size = ft_strlen(ft_itoa_base_ul(n, 10, 0));
    c_fill = (prm->flag == '0' || prm->flag_2 == '0') ? '0' : ' ';
	space = (prm->flag == ' ' || prm->flag_2 == ' ') ? 1 : 0;
	nbr_str = NULL;
    width = (prm->width >= prm->precision) ? prm->width : prm->precision;
    //  printf(" width: %d, size: %d ", width, size);
    if (width > size)
    {
        if (!(str = (char*)malloc(sizeof(char) * (width + 1))))
            ft_error(1);
        if (prm->width >= prm->precision)
            char_fill(str, width + 1, c_fill);
        else
            char_fill(str, width + 1, '0');
        nbr_str = ft_itoa_base_ul(n, 10, 0);
        //обработать если itoa вернет  NULL
        i = 0;
		if (prm->flag != '-' && prm->flag_2 != '-')
			i = width - size;
        j = 0;
        while (i + j < width + 1)
        {
            str[i + j] = nbr_str[j];
            j++;
        }
    }
    else
        str = ft_itoa_base_ul(n, 10, 0);
    if (space)
		ft_putchar(' ');
	ft_putstr(str);
    free(str);
    free(nbr_str);
}

