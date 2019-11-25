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
    int i;
    int j;
    //  int sign;
    int space;
    int width;
    int head;
    int plus;
    int hash;
    char c_fill;
    char* str;
    char* nbr_str;
    
    nbr_str = NULL;
    size = ft_strlen(ft_itoa_base_hhu(n, 16, cap));
    c_fill = (prm->flag == '0' || prm->flag_2 == '0' || prm->flag_3 == '0') ? '0' : ' ';
    space = (prm->flag == ' ' || prm->flag_2 == ' ' || prm->flag_3 == ' ') ? 1 : 0;
    head = (prm->flag == '-' || prm->flag_2 == '-' || prm->flag_3 == '-') ? 1 : 0;
    plus = (prm->flag == '+' || prm->flag_2 == '+' || prm->flag_3 == '+') ? 1 : 0;
    hash = (prm->flag == '#' || prm->flag_2 == '#' || prm->flag_3 == '#') ? 1 : 0;
    hash = (n == 0 && prm->precision == -1) ? 0 : hash;
    
    width = (prm->width >= prm->precision) ? prm->width : prm->precision;
    if (width > size)
    {
        if (hash && prm->precision > prm->width)
        {
            //printf("case\n");
            if (!(str = (char*)malloc(sizeof(char) * (width + 1))))
                ft_error(1);
        }
        else if(space && head && prm->width > prm->precision && prm->width > size)
        {
            if (!(str = (char*)malloc(sizeof(char) * (width + 2*hash))))
                ft_error(1);
            width += 2*hash - 1;
        }
        else if(space && c_fill == '0' && prm->width > prm->precision && prm->width > size && size > prm->precision)
        {
            if (prm->precision != -1 && !hash)
                width++;
            if (!(str = (char*)malloc(sizeof(char) * (width + 2*hash))))
                ft_error(1);
            width += 2*hash - 1;
        }
        else
        {
            if (!(str = (char*)malloc(sizeof(char) * (width + 1))))
                ft_error(1);
        }
        //        printf("width_-1: %zu", ft_strlen(str));
        
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
        nbr_str = ft_itoa_base_hhu(n, 16, cap);
        if (head && hash && (width > size + 2) && n && prm->width >= prm->precision)
        {
            str[0] = '0';
            str[1] = (!cap) ?'x' : 'X';
        }
        else if (head && hash && (width > size + 2) && n && prm->width < prm->precision)
        {
            if (!cap)
                ft_putstr("0x");
            else
                ft_putstr("0X");
        }
        else if (!head && hash && (prm->width < prm->precision) && n)
        {
            //            printf("case1");
            if (!cap)
                ft_putstr("0x");
            else
                ft_putstr("0X");
        }
        else if (hash && (width > size + 2) && n)
        {
            //            printf("case2\n");
            if (prm->precision <= size && (c_fill == ' ' || (c_fill == '0' && prm->precision != -1)))
            {
                //                printf("case1");
                str[width - size - 2] = '0';
                str[width - size - 1] = (!cap) ? 'x' : 'X';
            }
            else if (prm->precision <= size && c_fill == '0')
            {
                str[0] = '0';
                str[1] = (!cap) ? 'x' : 'X';
            }
            else
            {
                str[width - prm->precision - 2] = '0';
                str[width - prm->precision - 1] = (!cap) ? 'x' : 'X';
            }
            
        }
        else if (hash && width < size + 2)
        {
            if (!cap)
                ft_putstr("0x");
            else
                ft_putstr("0X");
            ft_putstr(nbr_str);
            return ;
        }
        
        
        i = 0;
        if ((hash && head) && n)
        {
            //            printf("case1");
            if (prm->precision <= size)
                i = 2;
            else if (prm->precision >= prm->width)
                i = prm->precision - size;
            else
                i = prm->precision - size + 2;
        }
        else if (!head)
            i = width + 2 * hash - size - 2 * hash;
        else if (prm->precision > size && head)
            i = prm->precision - size;
        j = 0;
        
        while (nbr_str[j] && str[i + j])
        {
            //нули с нулевой точностью не выводяться
            if (!(!n && prm->precision == 0))
                str[i + j] = nbr_str[j];
            j++;
        }
        // мы не ставим пробел из-за флага space если пробелы уже стоят из-за других причин
        if (space && !plus && str[0] != ' ')
            ft_putchar(' ');
        ft_putstr(str);
        free(str);
    }
    else
    {
        if (!n && prm->precision == 0)
        {
            //            if (hash)
            //                ft_putstr("0x");
        }
        else
        {
            if (space && !hash)
                ft_putchar(' ');
            if (plus)
                ft_putchar('+');
            if (hash && !cap)
                ft_putstr("0x");
            else if (hash && cap)
                ft_putstr("0X");
            ft_putstr(ft_itoa_base_hhu(n, 16, cap));
        }
    }
 
}

