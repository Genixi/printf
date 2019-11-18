/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:39:34 by equiana           #+#    #+#             */
/*   Updated: 2019/11/18 21:53:07 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
void ft_put_str(char *s, t_param *prm)
{
	int size;
	int width;
	int space;
	int i;
	int j;
	char c_fill;
	char *str;

	i = 0;
	j = 0;
	c_fill = (prm->flag == '0' || prm->flag_2 == '0') ? '0' : ' ';
	space = (prm->flag == ' ' || prm->flag_2 == ' ') ? 1 : 0;
	size = ft_strlen(s);
	width = -1;
	
	if (space)
		ft_putchar(' ');
	
	if (prm->precision > 0 && (prm->flag == '-' || prm->flag_2 == '-'))
	{
		while (s[i] && i < prm->precision)
			ft_putchar(s[i++]);
		return ;
	}
	
	if (prm->width > size)
		width = prm->width;
	else if (prm->precision > 0 && prm->precision < size)
		width = prm->precision;
	else if (prm->width != 0 && prm->precision == 0)
	{
		if (!(str = (char*)malloc(sizeof(char) * (prm->width + 1))))
			ft_error(1);
		char_fill(str, prm->width + 1, c_fill);
		str[prm->width] = '\0';
		ft_putstr(str);
		free(str);
		return ;
	}
	else if (prm->precision >= size)
	{
		ft_putstr(s);
		return ;
	}
//	printf(" size: %d, widht: %d\n", size, width);
	if (width >= 0)
	{
		if (!(str = (char*)malloc(sizeof(char) * (width + 1))))
			ft_error(1);
		char_fill(str, width + 1, ' ');
		if (prm->precision < size)
			i = width - (prm->precision - 1) - 1;
		else
			i = width - (size - 1) - 1;
		while (i + j < width)
		{
			str[i + j] = s[j];
			j++;
		}
		ft_putstr(str);
		free(str);
	}
	else
		ft_putstr(s);
}
