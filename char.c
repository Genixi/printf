/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:36:42 by equiana           #+#    #+#             */
/*   Updated: 2019/11/11 16:52:19 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

void ft_put_char(char c, t_param *prm)
{
	char *str;

	if (prm->width > 1)
	{
		if (!(str = (char*)malloc(sizeof(char) * (prm->width + 1))))
			ft_error(1);
		char_fill(str, prm->width + 1, ' ');
		str[prm->width] = '\0';
		str[prm->width - 1] = c;
		ft_putstr(str);
		free(str);
	}
	else
		write(1, &c, 1);
}
