/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_oct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:59:47 by equiana           #+#    #+#             */
/*   Updated: 2019/11/18 17:45:25 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include "stdlib.h"
#include <stdio.h>

void    ft_putnbr_ho(unsigned short int n, t_param *prm)
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
	size = ft_strlen(ft_itoa_base_hu(n, 8, 0));
    width = (prm->width >= prm->precision) ? prm->width : prm->precision;
    //    printf("check width: %d, sign: %d\n", width, sign);
    if (width > size)
    {
		if (!(str = (char*)malloc(sizeof(char) * (width + 1))))
        	ft_error(1);
        if (prm->width >= prm->precision)
            char_fill(str, width + 1, c_fill);
        else
            char_fill(str, width + 1, '0');
        //        printf("str: %s\n", str);
        nbr_str = ft_itoa_base_hu(n, 8, 0);
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
		str = ft_itoa_base_hu(n, 8, 0);
    if (space)
		ft_putchar(' ');
	ft_putstr(str);
    free(str);
    free(nbr_str);
}
