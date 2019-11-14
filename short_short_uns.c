/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_short_uns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:28:34 by equiana           #+#    #+#             */
/*   Updated: 2019/11/14 20:55:34 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include "stdlib.h"
#include <stdio.h>

char        *ft_itoa_base_hhu(unsigned char value, int base, int cap)
{
    int                len;
    unsigned char      nbr;
    char            *res;
    char            *base_str = "0123456789abcdef";
    char            *base_str_cap = "0123456789ABCDEF";
    
    if (value == 0)
        return ("0");
    len = 0;
    nbr = value;
    while (nbr)
    {
        nbr /= base;
        len += 1;
    }
    nbr = value;
    if (!(res = (char *)malloc(sizeof(char) * len + 1)))
        return (NULL);
    res[len] = '\0';
    while (nbr)
    {
        if (cap == 0)
            res[--len] = base_str[nbr % base];
        else
            res[--len] = base_str_cap[nbr % base];
        nbr /= base;
    }
    return (res);
}
void    ft_putnbr_hhu(unsigned char n, t_param *prm)
{
    int    size;
    int i;
    int j;
    int width;
    char* str;
    char* nbr_str;
    
    nbr_str = NULL;
    size = get_num_len(n);
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
        nbr_str = ft_itoa_base_hhu(n, 10, 0);
        //        printf("nbr_str: %s\n", nbr_str);
        //обработать если itoa вернет  NULL
        i = width - size - 1;
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
		str = ft_itoa_base_hhu(n, 10, 0);
    ft_putstr(str);
    free(str);
    free(nbr_str);
}
