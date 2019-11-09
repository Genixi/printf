/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:59:19 by equiana           #+#    #+#             */
/*   Updated: 2019/11/09 15:27:57 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_putnbr_l(long l)
{
	long nbr;

	nbr = l;
	if (nbr >= 10)
		ft_putnbr_l(nbr / 10);
	ft_putchar((char)(nbr % 10 + 48));
}

void	ft_putnbr_hex(int l)
{
	ft_putstr(ft_itoa_base(l, 16));
}

void	ft_putnbr_oct(int l)
{
	ft_putstr(ft_itoa_base(l, 8));
}
