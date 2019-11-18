/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:26:51 by equiana           #+#    #+#             */
/*   Updated: 2019/11/18 17:43:21 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include "stdlib.h"
#include <stdio.h>

char        *ft_itoa_base_hi(short int value, int base, int cap)
{
    int                len;
    short int        nbr;
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

void    ft_putnbr_hi(short int n, t_param *prm)
{
	int	size;
	int i;
    int j;
	int sign;
	int	space;
	int width;
	char c_fill;
	char* str;
	char* nbr_str;
    
	nbr_str = NULL;
	size = get_num_len(n);
	c_fill = (prm->flag == '0' || prm->flag_2 == '0') ? '0' : ' ';
	space = (prm->flag == ' ' || prm->flag_2 == ' ') ? 1 : 0;
	sign = (n < 0) ? 1 : 0;
	
	if (prm->flag == '+' || prm->flag_2 == '+')
		sign = 1;

	width = (prm->width >= prm->precision) ? prm->width : prm->precision;
//	printf("check width: %d, sign: %d\n", width, sign);	
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
//		printf("str: %s\n", str);
		nbr_str = (sign == 1) ? ft_itoa_base_hi(-n, 10, 0) : ft_itoa_base_hi(n, 10, 0);
		if (sign && prm->width < prm->precision)
			str[0] = (n < 0) ? '-' : '+';
		else if (sign && prm->width >= prm->precision)
			str[width + sign - size - 2] = str[0] = (n < 0) ? '-' : '+';
//		printf("nbr_str: %s\n", nbr_str);
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
//		printf("str: %s\n", str);
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
