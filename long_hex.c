/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:47:14 by equiana           #+#    #+#             */
/*   Updated: 2019/11/15 16:39:02 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void    ft_putnbr_lx(unsigned long int n, t_param *prm, int cap)
{
    int size;
    int i;
    int j;
    int width;
    char* str;
    char* nbr_str;
    
    size = ft_strlen(ft_itoa_base_ul(n, 16, cap));
    nbr_str = NULL;
    width = (prm->width >= prm->precision) ? prm->width : prm->precision;
    //  printf(" width: %d, size: %d ", width, size);
    if (width > size)
    {
        if (!(str = (char*)malloc(sizeof(char) * (width + 1))))
            ft_error(1);
        if (prm->width >= prm->precision)
            char_fill(str, width + 1, ' ');
        else
            char_fill(str, width + 1, '0');
        nbr_str = ft_itoa_base_ul(n, 16, cap);
        //обработать если itoa вернет  NULL
        i = width - size;
        //        printf("i: %d\n", i);
        j = 0;
        while (i + j < width + 1)
        {
            str[i + j] = nbr_str[j];
            j++;
        }
    }
    else
        str = ft_itoa_base_ul(n, 16, cap);
    ft_putstr(str);
    free(str);
    free(nbr_str);
}
