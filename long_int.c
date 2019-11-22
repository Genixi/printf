/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:48:09 by equiana           #+#    #+#             */
/*   Updated: 2019/11/22 14:14:32 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <stdlib.h>

char        *ft_itoa_base_ul(unsigned long long int value, int base, int cap)
{
    int                len;
    unsigned long long int        nbr;
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

char        *ft_itoa_base_li(long int value, int base, int cap)
{
    int                len;
    long int        nbr;
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

void    ft_putnbr_li(long int n, t_param *prm)
{
    int    size;
    int i;
    int j;
    int sign;
    int space;
    int width;
    int head;
    int plus;
    char c_fill;
    char* str;
    char* nbr_str;
    
    nbr_str = NULL;
    size = get_num_len(n);
    c_fill = (prm->flag == '0' || prm->flag_2 == '0' || prm->flag_3 == '0') ? '0' : ' ';
    space = (prm->flag == ' ' || prm->flag_2 == ' ' || prm->flag_3 == ' ') ? 1 : 0;
    head = (prm->flag == '-' || prm->flag_2 == '-' || prm->flag_3 == '-') ? 1 : 0;
    plus = (prm->flag == '+' || prm->flag_2 == '+' || prm->flag_3 == '+') ? 1 : 0;
    sign = (n < 0 || plus) ? 1 : 0;
    
    //    sign = (n < 0) ? 1 : 0;
    //    if (prm->flag == '+' || prm->flag_2 == '+')
    //        sign = 1;
    
    width = (prm->width >= prm->precision) ? prm->width : prm->precision;
    //    printf("flag: %c, flag_2: %c ", prm->flag, prm->flag_2);
    //    printf(" width: %d, sign: %d, size: %d, c_fill: %c printf: ", width, sign, size, c_fill);
    if (width > size)
    {
        if (sign && prm->precision > prm->width)
        {
            if (!(str = (char*)malloc(sizeof(char) * (width + sign + 1))))
                ft_error(1);
            width++;
        }
        //        else if(space && head && prm->width > prm->precision && prm->width > size && size > prm->precision)
        else if(space && head && prm->width > prm->precision && prm->width > size)
        {
            if (!(str = (char*)malloc(sizeof(char) * (width + sign))))
                ft_error(1);
            width += sign - 1;
        }
        else if(space && c_fill == '0' && prm->width > prm->precision && prm->width > size && size > prm->precision)
        {
            if (prm->precision != -1 && !sign)
                width++;
            if (!(str = (char*)malloc(sizeof(char) * (width + sign))))
                ft_error(1);
            width += sign -1;
        }
        else
            if (!(str = (char*)malloc(sizeof(char) * (width + 1))))
                ft_error(1);
        //        printf("width_-1: %zu", ft_strlen(str));
        //
        
        char_fill(str, 0, width + 1, ' ', 1);
        
        if (prm->width > prm->precision && prm->precision > size && !head)
            char_fill(str, prm->width - prm->precision, prm->width + 1, '0', 1);
        else if (prm->width > prm->precision && prm->precision > size && head)
            char_fill(str, 0, prm->precision, '0', 0);
        else if (prm->width > prm->precision && prm->precision == -1 && c_fill == '0')
            char_fill(str, 0, width + 1, '0', 1);
        else if (prm->width < prm->precision && prm->precision > size)
            char_fill(str, 0, width + 1, '0', 1);
        
        //        printf("str: %s\n", str);
        //        printf("width_0: %zu", ft_strlen(str));
        nbr_str = (n < 0) ? ft_itoa_base_li(-n, 10, 0) : ft_itoa_base_li(n, 10, 0);
        if (head && sign)
            str[0] = (n < 0) ? '-' : '+';
        //        else if (head && space)
        //            str[0] = (n < 0) ? '-' : ' ';
        else if (!head && sign && prm->width < prm->precision)
            str[0] = (n < 0) ? '-' : '+';
        else if (!head && sign && prm->width >= prm->precision && prm->precision <= size)
        {
            if (c_fill == '0' && prm->precision == -1)
                str[0] = (n < 0) ? '-' : '+';
            else
                str[width + sign - size - 2] = (n < 0) ? '-' : '+';
        }
        else if (!head && sign && prm->width >= prm->precision && prm->precision > size)
        {
            str[prm->width - prm->precision - 1] = (n < 0) ? '-' : '+';
        }
        
        i = (str[0] == '-' || str[0] == '+') ? 1 : 0;
        if (!head)
            i = width + sign - size - 1 * sign;
        else if (prm->precision > size && head)
            i = prm->precision - size + sign;
        j = 0;
        
        //        printf("nbr: %s", nbr_str);
        
        while (nbr_str[j] && str[i + j])
        {
            str[i + j] = nbr_str[j];
            j++;
        }
        // мы не ставим пробел из-за флага space если пробелы уже стоят из-за других причин
        if (space && n >= 0 && !plus && str[0] != ' ')
            ft_putchar(' ');
        //            if (((i > 0 && str[i - 1] != ' ') || i == 0))
        //                ft_putchar(' ');
        
        //        printf("width_end: %zu", ft_strlen(str));
        //        if (space && !sign &&)
        //            ft_putchar(' ');
        //чистить за собой nbr_str, т.к. он не нужен
        ft_putstr(str);
        //        printf("%s", str);
        free(str);
        //        free(nbr_str);
    }
    else
    {
        if (space && !sign)
            ft_putchar(' ');
        if (plus && n >= 0)
            ft_putchar('+');
        nbr_str = (n < 0) ? ft_itoa_base_li(-n, 10, 0) : ft_itoa_base_li(n, 10, 0);
        if (n < 0)
            ft_putchar('-');
        ft_putstr(nbr_str);
    }
}
