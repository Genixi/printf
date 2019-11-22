/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_oct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:44:52 by equiana           #+#    #+#             */
/*   Updated: 2019/11/22 14:19:48 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <stdlib.h>

void    ft_putnbr_lo(unsigned long int n, t_param *prm)
{
    int size;
    int space;
	int i;
    int j;
    int width;
    char c_fill;
	char* str;
    char* nbr_str;
    
    c_fill = (prm->flag == '0' || prm->flag_2 == '0') ? '0' : ' ';
	size = ft_strlen(ft_itoa_base_ul(n, 8, 0));
    space = (prm->flag == ' ' || prm->flag_2 == ' ') ? 1 : 0;
	nbr_str = NULL;
    width = (prm->width >= prm->precision) ? prm->width : prm->precision;
//  printf(" width: %d, size: %d ", width, size); 
	if (width > size)
    {
		if (!(str = (char*)malloc(sizeof(char) * (width + 1))))
			ft_error(1);
        if (prm->width >= prm->precision)
            char_fill(str, 0, width + 1, c_fill, 1);
        else
            char_fill(str, 0, width + 1, '0', 1);
        nbr_str = ft_itoa_base_ul(n, 8, 0);
        //обработать если itoa вернет  NULL
        i = 0;
		if (prm->flag != '-' && prm->flag_2 != '-')
			i = width - size;
        j = 0;
        while (nbr_str[j] && i + j < width + 1)
        {
            str[i + j] = nbr_str[j];
            j++;
        }
    }
    else
		str = ft_itoa_base_ul(n, 8, 0);
    if (space)
		ft_putchar(' ');
	ft_putstr(str);
    free(str);
    free(nbr_str);
}
