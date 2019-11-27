/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 22:00:11 by equiana           #+#    #+#             */
/*   Updated: 2019/11/27 16:56:16 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void ft_error(int n)
{
    if (n == 1)
        ft_putstr("malloc error\n");
    if (n == 2)
		ft_putstr("invalid %% format\n");
	exit(0);
}

double ft_power(double n, int pow)
{
	return (pow ? n * ft_power(n, pow - 1) : 1);
}

void display_str(t_param *prm)
{
	printf("flag: %c ", prm->flag);
	printf("width: %d ", prm->width);
	printf("precision: %d ", prm->precision);
	printf("modificator: %c ", prm->mod);
	printf("type: %c", prm->type);	
}

