/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octet.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:06:48 by equiana           #+#    #+#             */
/*   Updated: 2019/11/24 20:34:19 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>
#include <stdio.h>
void ft_putnbr_oct(unsigned int n, t_param *prm)
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
    size = ft_strlen(ft_itoa_base_u(n, 8, 0));
    c_fill = (prm->flag == '0' || prm->flag_2 == '0' || prm->flag_3 == '0') ? '0' : ' ';
    space = (prm->flag == ' ' || prm->flag_2 == ' ' || prm->flag_3 == ' ') ? 1 : 0;
    head = (prm->flag == '-' || prm->flag_2 == '-' || prm->flag_3 == '-') ? 1 : 0;
    plus = (prm->flag == '+' || prm->flag_2 == '+' || prm->flag_3 == '+') ? 1 : 0;
    hash = (prm->flag == '#' || prm->flag_2 == '#' || prm->flag_3 == '#') ? 1 : 0;
	hash = (n == 0 && prm->precision == -1) ? 0 : hash;
// sign меняем на hash
//	sign = (plus) ? 1 : 0;
    
    //    sign = (n < 0) ? 1 : 0;
    //    if (prm->flag == '+' || prm->flag_2 == '+')
    //        sign = 1;
    
    width = (prm->width >= prm->precision) ? prm->width : prm->precision;
    //    printf("flag: %c, flag_2: %c ", prm->flag, prm->flag_2);
    //    printf(" width: %d, sign: %d, size: %d, c_fill: %c printf: ", width, sign, size, c_fill);
    if (width > size)
    {
        if (hash && prm->precision > prm->width)
        {
			//printf("case\n");
            if (!(str = (char*)malloc(sizeof(char) * (width + 1))))
                ft_error(1);
           // width++;
        }
        //        else if(space && head && prm->width > prm->precision && prm->width > size && size > prm->precision)
        else if(space && head && prm->width > prm->precision && prm->width > size)
        {
            if (!(str = (char*)malloc(sizeof(char) * (width + hash))))
                ft_error(1);
            width += hash - 1;
        }
        else if(space && c_fill == '0' && prm->width > prm->precision && prm->width > size && size > prm->precision)
        {
            if (prm->precision != -1 && !hash)
                width++;
            if (!(str = (char*)malloc(sizeof(char) * (width + hash))))
                ft_error(1);
            width += hash - 1;
        }
        else
		{
            if (!(str = (char*)malloc(sizeof(char) * (width + 1))))
                ft_error(1);
		}
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
		{
			//printf("case11\n");
            char_fill(str, 0, width + 1, '0', 1);
		}
        
        //        printf("str: %s\n", str);
        //        printf("width_0: %zu", ft_strlen(str));
        nbr_str = ft_itoa_base_u(n, 8, 0);
	   	if (head && hash)
            str[0] = '0';
        else if (!head && hash && prm->width < prm->precision)
            str[0] = '0';
        else if (!head && hash && prm->width >= prm->precision && prm->precision == 0 && !n)
            str[ft_strlen(str) - 1] = '0';
        else if (!head && hash && prm->width >= prm->precision && prm->precision <= size)
        {
            if (c_fill == '0' && prm->precision == -1)
                str[0] = '0';
            else
                str[width + hash - size - 2] = '0';
        }
//        else if (!head && hash && prm->width >= prm->precision && prm->precision > size)
//        {
//            str[prm->width - prm->precision - 1] = '0';
//        }
        
        i = (str[0] == '-' || str[0] == '+' || (hash && str[0] == '0')) ? 1 : 0;
		if (!head)
            i = width + hash - size - 1 * hash;
        else if (prm->precision > size && head)
			i = prm->precision - size;
//          i = prm->precision - size + hash;
        j = 0;
       
//		printf("i: %d\n", i);
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
//			printf("case1\n");
            if (hash)
                ft_putchar('0');
        }
        else
        {
            if (space && !hash)
                ft_putchar(' ');
            if (plus)
                ft_putchar('+');
			if (hash)
				ft_putchar('0');
            ft_putstr(ft_itoa_base_u(n, 8, 0));
        }
    }
}
