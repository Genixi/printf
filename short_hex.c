/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:27:48 by equiana           #+#    #+#             */
/*   Updated: 2019/11/15 16:38:19 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include "stdlib.h"
#include <stdio.h>

void    ft_putnbr_hx(unsigned short int n, t_param *prm, int cap)
{
    int    size;
    int i;
    int j;
    int width;
    char* str;
    char* nbr_str;
    
    nbr_str = NULL;
    size = ft_strlen(ft_itoa_base_hu(n, 16, cap));
    width = (prm->width >= prm->precision) ? prm->width : prm->precision;
    //    printf("check width: %d, sign: %d\n", width, sign);
    if (width > size)
    {
        if (!(str = (char*)malloc(sizeof(char) * (width + 1))))
            ft_error(1);
        if (prm->width >= prm->precision)
            char_fill(str, width + 1, ' ');
        else
            char_fill(str, width + 1, '0');
        //        printf("str: %s\n", str);
        nbr_str = ft_itoa_base_hu(n, 16, cap);
        //        printf("nbr_str: %s\n", nbr_str);
        //обработать если itoa вернет  NULL
        i = width - size;
        //        printf("i: %d\n", i);
        j = 0;
        while (i + j < width + 1)
        {
            str[i + j] = nbr_str[j];
            j++;
        }
        //чистить за собой nbr_str, т.к. он не нужен
    }
    else
        str = ft_itoa_base_hu(n, 16, cap);
    ft_putstr(str);
    free(str);
    free(nbr_str);
}

