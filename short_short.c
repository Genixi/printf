/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_short.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:15:42 by equiana           #+#    #+#             */
/*   Updated: 2019/11/18 17:46:11 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include "stdlib.h"
#include <stdio.h>

void    ft_putnbr_hhi(signed char n, t_param *prm)
{
    int    size;
    int space;
	int i;
    int j;
    int sign;
    int width;
    char c_fill;
	char* str;
    char* nbr_str;
    
    nbr_str = NULL;
    c_fill = (prm->flag == '0' || prm->flag_2 == '0') ? '0' : ' ';
	space = (prm->flag == ' ' || prm->flag_2 == ' ') ? 1 : 0;
	size = get_num_len(n);
    sign = (n < 0) ? 1 : 0;

	if (prm->flag == '+' || prm->flag_2 == '+')
		sign = 1;

    width = (prm->width >= prm->precision) ? prm->width : prm->precision;
    //    printf("check width: %d, sign: %d\n", width, sign);
    if (width > size)
    {
        if (sign && prm->precision > prm->width)
        {
            if (!(str = (char*)malloc(sizeof(char) * (width + sign + 1))))
                ft_error(1);
            width++;
        }
        else
            if (!(str = (char*)malloc(sizeof(char) * (width + 1))))
                ft_error(1);
        if (prm->width >= prm->precision)
            char_fill(str, width + 1, c_fill);
        else
            char_fill(str, width + 1, '0');
        //        printf("str: %s\n", str);
        nbr_str = (sign == 1) ? ft_itoa_base_hi(-n, 10, 0) : ft_itoa_base_hi(n, 10, 0);
        if (sign && prm->width < prm->precision)
            str[0] = (n < 0) ? '-' : '+';
        else if (sign && prm->width >= prm->precision)
            str[width + sign - size - 2] = (n < 0) ? '-' : '+';
        //        printf("nbr_str: %s\n", nbr_str);
        //обработать если itoa вернет  NULL
        i = 0;
		if (prm->flag != '-' && prm->flag_2 != '-')
			i = width + sign - size - 1;
        j = 0;
        while (i + j < width + 1)
        {
            str[i + j] = nbr_str[j];
            j++;
        }
        if (space)
			ft_putchar(' ');
		//чистить за собой nbr_str, т.к. он не нужен
    }
    else
    {
        str = (sign) ? ft_itoa_base_hi(-n, 10, 0) : ft_itoa_base_hi(n, 10, 0);
        //        printf("str: %s\n", str);
        if (space)
			ft_putchar(' ');
		if (sign && n < 0)
            ft_putchar('-');
		else if (sign && n >= 0)
			ft_putchar('+');
    }
    ft_putstr(str);
    free(str);
    free(nbr_str);
}
