/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_h.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:40:16 by equiana           #+#    #+#             */
/*   Updated: 2019/11/13 17:16:39 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>

char		*ft_itoa_base_hi(short int value, int base, int cap)
{
	int				len;
	short int		nbr;
	char			*res;
	char			*base_str = "0123456789abcdef";
	char			*base_str_cap = "0123456789ABCDEF";

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
