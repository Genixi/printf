/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:41:15 by equiana           #+#    #+#             */
/*   Updated: 2019/11/16 17:20:54 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
static int    get_base_l(long double n, int *base_size)
{
    int base;
    
    base = 1;
    while ((long)(n))
    {
        if (n /= 10)
            base *= 10;
        (*base_size)++;
    }
    return (base);
}

void    ft_putnbr_lf(long double n, t_param *prm)
{
    int sign;
    int base;
    int base_size;
    int tmp;
    int width;
    char *res;
    char *str;
    int i;
    int j;
    
    i = 0;
    j = 0;
    str = NULL;
    res = NULL;
    base_size = 0;
    base = get_base_l(n, &base_size) / 10;
    sign = 0;
    if (n < 0)
    {
        sign = 1;
        n = -n;
    }
    base_size = (base_size == 0) ? 1 : base_size;
    width = prm->precision;
    if (!(res = (char*)malloc(sizeof(char) * (base_size + width + sign + 1))))
        ft_error(1);
    char_fill(res, base_size + width + sign + 1, '0');
    res[base + width + sign] = '\0';
    if (sign)
        res[i++] = '-';
    if (base)
        while ((long)n != 0)
        {
            res[i] = (char)(n / base + '0');
            n = n - (int)(n / base) * base;
            base = base / 10;
            i++;
        }
    else
        res[i++] = '0';
    res[i] = '.';
    i++;
    n = n * 10;
    //     printf("res 0: %s ", res);
    while (i < base_size +  width + sign + 1)
    {
        tmp = (int)n;
        res[i] = (char)(tmp + '0');
        n = (n - tmp) * 10;
        i++;
    }
    //    printf("res 1: %s ", res);
    if (prm->width > base_size + width + sign)
    {
        //        printf("case 1\n");
        if (!(str= (char*)malloc(sizeof(char) * (prm->width + 1))))
            ft_error(1);
        char_fill(str, prm->width + 1, ' ');
        i = prm->width - (base_size + width + sign) - 1;
        j = 0;
        while (i + j < prm->width + 1)
        {
            str[i + j] = res[j];
            j++;
        }
        str[prm->width] = '\0';
        //        printf(" str: %s\n", str);
        ft_putstr(str);
        //        free(str);
    }
    else
        ft_putstr(res);
    //!!!! почему то при очисте памяти происходит некорректный вывод - разобраться!!
    //    free(res);
    //    ft_putstr(res);
}
