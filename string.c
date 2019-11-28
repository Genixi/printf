/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:39:34 by equiana           #+#    #+#             */
/*   Updated: 2019/11/28 20:37:05 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void	str_output_1(char *s, int size, t_param *prm)
{
	int i;

	i = 0;
	if (prm->head && prm->precision == -1)
	{
		ft_putstr(s);
		if (prm->width > size)
			while (i++ < prm->width - size)
				ft_putchar(prm->c_fill);
	}
	else if (prm->head && prm->precision > 0)
	{
		while (s[i] && i < prm->precision)
			ft_putchar(s[i++]);
		if (prm->width > prm->precision)
			while (i++ < prm->width)
				ft_putchar(prm->c_fill);
	}
}

void	str_output_2(t_param *prm)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)malloc(sizeof(char) * (prm->width + 1));
	char_fill(str, 0, prm->width + 1, prm->c_fill, 1);
	while (i < prm->width + 1)
		ft_putchar(str[i++]);
	free(str);
}

void	str_output_3(char *s, int width, int size, t_param *prm)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	if (width >= 0)
	{
		str = (char*)malloc(sizeof(char) * (width + 1));
		char_fill(str, 0, width + 1, prm->c_fill, 1);
		if (prm->precision != -1 && prm->precision < size)
			i = width - (prm->precision - 1) - 1;
		else
			i = width - (size - 1) - 1;
		while (str[i + j] && s[j])
		{
			str[i + j] = s[j];
			j++;
		}
		i = 0;
		while (i < width)
			ft_putchar(str[i++]);
		free(str);
	}
	else
		ft_putstr(s);
}

void	ft_put_str(char *s, t_param *prm)
{
	if (prm->space)
		ft_putchar(' ');
	if (prm->head && (prm->precision == -1 || prm->precision > 0))
	{
		str_output_1(s, (int)ft_strlen(s), prm);
		return ;
	}
	if (prm->width > (int)ft_strlen(s) || (prm->width > 0 && prm->precision >= 0
				&& prm->precision < (int)ft_strlen(s)))
		str_output_3(s, prm->width, (int)ft_strlen(s), prm);
	else if (prm->precision >= 0 && prm->precision < (int)ft_strlen(s))
		str_output_3(s, prm->precision, (int)ft_strlen(s), prm);
	else if (prm->width != 0 && prm->precision == 0)
	{
		str_output_2(prm);
		return ;
	}
	else if (prm->precision >= (int)ft_strlen(s))
	{
		ft_putstr(s);
		return ;
	}
	else
		str_output_3(s, -1, (int)ft_strlen(s), prm);
}
