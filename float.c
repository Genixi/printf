/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:59:41 by equiana           #+#    #+#             */
/*   Updated: 2019/11/26 16:06:28 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void ft_putnbr_f(double n, t_param *prm)
{
	double long decimal;
	unsigned long n_ul;
	long	decimal_l;
	int width;
	int sign;
	int size;
	int precision;

	sign = (n < 0) ? 1 : 0;
	n = (n < 0) ? n *= -1 : n;
	precision = (prm->precision == -1) ? 6 : prm->precision;
	decimal = (n - (long)n) * ft_iterative_power(10, precision + 1);
	decimal = ((long)decimal % 10 > 4) ? (decimal) / 10 + 1 : decimal / 10;
	n_ul = (long)n + (long)(decimal / ft_iterative_power(10, precision));
	decimal_l = (long)decimal % (long)ft_iterative_power(10, precision);
	size = get_num_len(n_ul);
	width = 


	
}
