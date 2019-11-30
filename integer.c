/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:32:20 by equiana           #+#    #+#             */
/*   Updated: 2019/11/30 17:43:55 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void	set_str(char **str, t_param *prm, int *width, int n)
{
	int size;
	int sign;

	size = get_num_len(n);
	sign = (n < 0 || prm->plus) ? 1 : 0;
	if (sign && prm->precision > prm->width)
		(*str) = (char*)malloc(sizeof(char) * (sign + 1 + (*width)++));
	else if (prm->space && prm->head && prm->width > prm->precision &&
			prm->width > size)
	{
		(*str) = (char*)malloc(sizeof(char) * (*width + sign));
		(*width) += sign - 1;
	}
	else if (prm->space && prm->c_fill == '0' &&
			prm->width > prm->precision && prm->width > size &&
			size > prm->precision)
	{
		if (prm->precision != -1 && !sign)
			(*width)++;
		(*str) = (char*)malloc(sizeof(char) * ((*width) + sign));
		(*width) += sign - 1;
	}
	else
		(*str) = (char*)malloc(sizeof(char) * ((*width) + 1));
	char_fill_eof(*str, 0, (*width) + 1, ' ');
}

void	fill_str(char **str, t_param *prm, t_sup *t, int n)
{
	int pr;

	if (prm->width > (pr = prm->precision) && pr > t->size && !prm->head)
		char_fill_eof(*str, prm->width - pr, prm->width + 1, '0');
	else if (prm->width > pr && pr > t->size && prm->head)
		char_fill_0(*str, 0, pr, '0');
	else if ((prm->width > pr && pr == -1 &&
			prm->c_fill == '0') || (prm->width < pr && pr > t->size))
		char_fill_eof(*str, 0, t->width + 1, '0');
	if ((prm->head && t->sign) || (!prm->head && t->sign && prm->width < pr))
		(*str)[0] = (n < 0) ? '-' : '+';
	else if (!prm->head && t->sign && prm->width >= pr && pr == 0 && !n)
		(*str)[ft_strlen(*str) - 1] = '+';
	else if (!prm->head && t->sign && prm->width >= pr && pr <= t->size)
	{
		if (prm->c_fill == '0' && pr == -1)
			(*str)[0] = (n < 0) ? '-' : '+';
		else
			(*str)[t->width + t->sign - t->size - 2] = (n < 0) ? '-' : '+';
	}
	else if (!prm->head && t->sign && prm->width >= pr && pr > t->size)
		(*str)[prm->width - pr - 1] = (n < 0) ? '-' : '+';
}

void	put_str(char **str, t_param *prm, int width, int n)
{
	int		i;
	int		j;
	int		sign;
	int		size;
	char	*nbr_str;

	sign = (n < 0 || prm->plus) ? 1 : 0;
	size = get_num_len(n);
	nbr_str = (n < 0) ? ft_itoa_base(-n, 10) : ft_itoa_base(n, 10);
	i = ((*str)[0] == '-' || (*str)[0] == '+') ? 1 : 0;
	if (!prm->head)
		i = width + sign - size - 1 * sign;
	else if (prm->precision > size && prm->head)
		i = prm->precision - size + sign;
	j = 0;
	while (nbr_str[j] && (*str)[i + j])
	{
		if (!(!n && prm->precision == 0))
			(*str)[i + j] = nbr_str[j];
		j++;
	}
	if (prm->space && n >= 0 && !prm->plus && (*str)[0] != ' ')
		ft_putchar(' ');
	ft_putstr(*str);
}

void	put_str_simple(int n, t_param *prm)
{
	int sign;

	sign = (n < 0 || prm->plus) ? 1 : 0;
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

void	ft_putnbr_i(int n, t_param *prm)
{
	int		size;
	int		sign;
	int		width;
	char	*str;
	t_sup	tmp;

	size = get_num_len(n);
	sign = (n < 0 || prm->plus) ? 1 : 0;
	width = (prm->width >= prm->precision) ? prm->width : prm->precision;
	if (width > size)
	{
		set_str(&str, prm, &width, n);
		tmp.size = size;
		tmp.sign = sign;
		tmp.width = width;
		fill_str(&str, prm, &tmp, n);
		put_str(&str, prm, width, n);
		free(str);
	}
	else
		put_str_simple(n, prm);
}
