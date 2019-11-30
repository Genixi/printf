/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:32:20 by equiana           #+#    #+#             */
/*   Updated: 2019/11/30 15:24:16 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void	char_fill(char *str, int start, int end, char c, int eof)
{
	int i;

	i = start;
	while (i < end)
		str[i++] = c;
	if (eof)
		str[end - 1] = '\0';
}

void    ft_putnbr_i(int n, t_param *prm)
{
	int	size;
	int i;
    int j;
	int sign;
	int width;
	char* str;
	char* nbr_str;
    
	nbr_str = NULL;
	size = get_num_len(n);
	sign = (n < 0 || prm->plus) ? 1 : 0;
	
	width = (prm->width >= prm->precision) ? prm->width : prm->precision;
	if (width > size)
	{
		if (sign && prm->precision > prm->width)
		{
			if (!(str = (char*)malloc(sizeof(char) * (width + sign + 1))))
				ft_error(1);
			width++;
		}
		else if(prm->space && prm->head && prm->width > prm->precision && prm->width > size)
		{
			if (!(str = (char*)malloc(sizeof(char) * (width + sign))))
				ft_error(1);
			width += sign - 1;			
		}
		else if(prm->space && prm->c_fill == '0' && prm->width > prm->precision && prm->width > size && size > prm->precision)
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
		char_fill(str, 0, width + 1, ' ', 1);
		
		if (prm->width > prm->precision && prm->precision > size && !prm->head)
			char_fill(str, prm->width - prm->precision, prm->width + 1, '0', 1);
		else if (prm->width > prm->precision && prm->precision > size && prm->head)
			char_fill(str, 0, prm->precision, '0', 0);
		else if (prm->width > prm->precision && prm->precision == -1 && prm->c_fill == '0')
			char_fill(str, 0, width + 1, '0', 1);
		else if (prm->width < prm->precision && prm->precision > size)
			char_fill(str, 0, width + 1, '0', 1);
		nbr_str = (n < 0) ? ft_itoa_base(-n, 10) : ft_itoa_base(n, 10);
		
		if (prm->head && sign)
			str[0] = (n < 0) ? '-' : '+';
		else if (!prm->head && sign && prm->width < prm->precision)
			str[0] = (n < 0) ? '-' : '+';
		else if (!prm->head && sign && prm->width >= prm->precision && prm->precision == 0 && !n)
			str[ft_strlen(str) - 1] = '+';
		else if (!prm->head && sign && prm->width >= prm->precision && prm->precision <= size)
		{
			if (prm->c_fill == '0' && prm->precision == -1)
				str[0] = (n < 0) ? '-' : '+';
			else
				str[width + sign - size - 2] = (n < 0) ? '-' : '+';
		}
		else if (!prm->head && sign && prm->width >= prm->precision && prm->precision > size)
		{
			str[prm->width - prm->precision - 1] = (n < 0) ? '-' : '+';
		}

		i = (str[0] == '-' || str[0] == '+') ? 1 : 0;
		if (!prm->head)
			i = width + sign - size - 1 * sign;
		else if (prm->precision > size && prm->head)
			i = prm->precision - size + sign;
		j = 0;

		while (nbr_str[j] && str[i + j])
		{
			if (!(!n && prm->precision == 0))
				str[i + j] = nbr_str[j];
			j++;
		}
// мы не ставим пробел из-за флага space если пробелы уже стоят из-за других причин
		if (prm->space && n >= 0 && !prm->plus && str[0] != ' ')
			ft_putchar(' ');
		ft_putstr(str);
		free(str);
	}
	else
	{
		if (!n && prm->precision == 0)
		{
			if (sign)
				ft_putchar('+');
		}
		else
		{
			if (prm->space && !sign)
				ft_putchar(' ');
			if (prm->plus && n >= 0)
				ft_putchar('+');
			ft_putstr(ft_itoa_base(n, 10));
		}		
	}
}
