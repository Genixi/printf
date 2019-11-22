/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_short_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:36:32 by equiana           #+#    #+#             */
/*   Updated: 2019/11/18 17:49:30 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>
#include <stdio.h>


void    ft_putnbr_hhx(unsigned char n, t_param *prm, int cap)
{
    int    size;
    int space;
	int i;
    int j;
    int width;
    char c_fill;
	char* str;
    char* nbr_str;
    
    nbr_str = NULL;
    c_fill = (prm->flag == '0' || prm->flag_2 == '0') ? '0' : ' ';
	space = (prm->flag == ' ' || prm->flag_2 == ' ') ? 1 : 0;
	size = ft_strlen(ft_itoa_base_hu(n, 16, cap));
    width = (prm->width >= prm->precision) ? prm->width : prm->precision;
    //    printf("check width: %d, sign: %d\n", width, sign);
    if (width > size)
    {
        if (!(str = (char*)malloc(sizeof(char) * (width + 1))))
            ft_error(1);
        if (prm->width >= prm->precision)
            char_fill(str, 0, width + 1, c_fill, 1);
        else
            char_fill(str, 0, width + 1, '0', 1);
        //        printf("str: %s\n", str);
        nbr_str = ft_itoa_base_hhu(n, 16, cap);
        //        printf("nbr_str: %s\n", nbr_str);
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
        //чистить за собой nbr_str, т.к. он не нужен
    }
    else
        str = ft_itoa_base_hhu(n, 16, cap);
    if (space)
		ft_putchar(' ');
	ft_putstr(str);
    free(str);
    free(nbr_str);
}

