/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:59:41 by equiana           #+#    #+#             */
/*   Updated: 2019/11/27 15:55:11 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
void put_sign( )

void ft_put_f(t_nbr *tmp, t_param *prm)
{
	if (prm->null && !prm->head)
	{

	}
	

}

void ft_putnbr_f(double n, t_param *prm)
{
	double long decimal;
	t_nbr tmp;
	int sign;
	int hash;
	int plus;
	int space;
	int precision;

	sign = (n < 0) ? 1 : 0;
	n = (n < 0) ? n *= -1 : n;
	precision = (prm->precision == -1) ? 6 : prm->precision;
	decimal = (n - (long)n) * ft_iterative_power(10, precision + 1);
	decimal = ((long)decimal % 10 > 4) ? (decimal) / 10 + 1 : decimal / 10;
	tmp.n = (long)n + (long)(decimal / ft_iterative_power(10, precision));
	tmp.decimal = (long)decimal % (long)ft_iterative_power(10, precision);
	tmp.size = get_num_len(n_ul);
	tmp.width = (prm->width > tmp.size + precision) ? (tmp.width - tmp.len - precision) : tmp.width;
	if (prm->hash || prm->precision != -1)
		tmp.width--;
	if (prm->space || prm->plus || sign)
		tmp.width--;
	ft_put_f(&tmp, prm);	
}
