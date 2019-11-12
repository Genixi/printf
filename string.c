/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:39:34 by equiana           #+#    #+#             */
/*   Updated: 2019/11/11 18:51:42 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <stdio.h>
void ft_put_str(char *s, t_param *prm)
{
	int size;
	int width;
	int i;
	int j;
	char *str;

	i = 0;
	j = 0;
	size = ft_strlen(s);
	width = -1;
	if (prm->width > size)
		width = prm->width;
	else if (prm->precision > 0 && prm->precision < size)
		width = prm->precision;
	else if (prm->width != 0 && prm->precision == 0)
	{
		if (!(str = (char*)malloc(sizeof(char) * (prm->width + 1))))
			ft_error(1);
		char_fill(str, prm->width + 1, ' ');
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