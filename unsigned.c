/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:15:40 by equiana           #+#    #+#             */
/*   Updated: 2019/11/15 17:18:10 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char        *ft_itoa_base_u(unsigned int value, int base, int cap)
{
    int                len;
    unsigned int    nbr;
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

void    ft_putnbr_u(unsigned int n, t_param *prm)
{
	int size;
	int i;
    int j;
	int width;
	char* str;
	char* nbr_str;

	size = get_num_len(n);
	nbr_str = NULL;
	width = (prm->width >= prm->precision) ? prm->width : prm->precision;
	if (width > size)
	{
		if (!(str = (char*)malloc(sizeof(char) * (width + 1))))
			ft_error(1);
		if (prm->width >= prm->precision)
			char_fill(str, width + 1, ' ');
		else
			char_fill(str, width + 1, '0');
		if (prm->width > prm->precision && prm->precision > size)
			char_fill(str + prm->width - prm->precision, prm->precision, '0');
		nbr_str = ft_itoa_base_u(n, 10, 0);
		//обработать если itoa вернет  NULL
		i = width - size - 1;
		j = 0;
		while (i + j < width + 1)
		{
			str[i + j] = nbr_str[j];
			j++;
		}		
	}
	else
		str = ft_itoa_base_u(n, 10, 0);
	ft_putstr(str);
	free(str);
	free(nbr_str);
}

