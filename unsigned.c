/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:15:40 by equiana           #+#    #+#             */
/*   Updated: 2019/11/09 15:40:32 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <stdio.h>

void    ft_putnbr_u(unsigned int n, t_param *prm)
{
	int	size;
	int i;
    int j;
	char* str;
	char* nbr_str;
    
	size = get_num_len(n);
	if (prm->width != -1 && prm->width > size)
	{
		if (!(str = (char*)malloc(sizeof(char) * (prm->width + 1))))
			ft_error(1);
		char_fill(str, prm->width + 1, ' ');
		nbr_str = ft_itoa_base(n, 10);
//		printf("nbr_str: %s\n", nbr_str);
		//обработать если itoa вернет  NULL
		i = prm->width - size - 1;
		j = 0;
		while (i + j < prm->width + 1)
		{
			str[i + j] = nbr_str[j];
			j++;
		}
		//чистить за собой nbr_str, т.к. он не нужен
	}
	else
		str = ft_itoa_base(n, 10);
	ft_putstr(str);
}

