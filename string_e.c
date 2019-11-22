/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_e.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:18:19 by equiana           #+#    #+#             */
/*   Updated: 2019/11/22 14:11:01 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
void ft_put_str_e(char *s, t_param *prm)
{
    int size;
    int width;
    int space;
    int i;
    int j;
    char c_fill;
    char *str;
	char tmp[7];
    
    i = 0;
    j = 0;
	ft_strcpy(tmp, "(null)");
    c_fill = (prm->flag == '0' || prm->flag_2 == '0') ? '0' : ' ';
    space = (prm->flag == ' ' || prm->flag_2 == ' ') ? 1 : 0;
    size = 6;
    width = -1;
	s = NULL;
   
    if (space)
        ft_putchar(' ');
    
    if ((prm->flag == '-' || prm->flag_2 == '-') && prm->precision == -1)
    {
        ft_putstr(tmp);
        if (prm->width > size)
            while (i++ < prm->width - size)
                ft_putchar(c_fill);
        return ;
    }
    else if ((prm->flag == '-' || prm->flag_2 == '-') && prm->precision > 0)
    {
        while (tmp[i] && i < prm->precision)
            ft_putchar(tmp[i++]);
        if (prm->width > prm->precision)
            while (i++ < prm->width)
                ft_putchar(c_fill);
        return ;
    }
    
    /*
     ** define width
     */
    if (prm->width > size)
        width = prm->width;
    else if (prm->width > 0 && prm->precision >= 0 && prm->precision < size)
        width = prm->width;
    else if (prm->precision >= 0 && prm->precision < size)
        width = prm->precision;
    else if (prm->width != 0 && prm->precision == 0)
    {
        if (!(str = (char*)malloc(sizeof(char) * (prm->width + 1))))
            ft_error(1);
        char_fill(str, 0, prm->width + 1, c_fill, 1);
        str[prm->width] = '\0';
        i = 0;
        while (i < prm->width + 1)
            ft_putchar(str[i++]);
        //        ft_putstr(str);
        free(str);
        return ;
    }
    else if (prm->precision >= size)
    {
        ft_putstr(tmp);
        return ;
    }
    
    //    printf(" width: %d", width);
    
    if (width >= 0)
    {
        if (!(str = (char*)malloc(sizeof(char) * (width + 1))))
            ft_error(1);
        char_fill(str, 0, width + 1, c_fill, 1);
        str[width] = '\0';
        if (prm->precision != -1 && prm->precision < size)
            i = width - (prm->precision - 1) - 1;
        else
            i = width - (size - 1) - 1;
        while (str[i + j] && tmp[j])
        {
            str[i + j] = tmp[j];
            j++;
        }
        
        //        printf("\ntest width: %d, str: %s\n", width, str);
        
        i = 0;
        while (i < width)
        {
            ft_putchar(str[i]);
            i++;
        }
        //        ft_putstr(str);
        free(str);
    }
    else
        ft_putstr(tmp);
}
