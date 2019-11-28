/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:36:42 by equiana           #+#    #+#             */
/*   Updated: 2019/11/28 18:09:41 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_put_char(char c, t_param *prm)
{
	char	*str;
	int		i;

	i = 0;
	if (prm->space)
		ft_putchar(' ');
	if (prm->width > 1)
	{
		if (!(str = (char*)malloc(sizeof(char) * (prm->width + 1))))
			ft_error(1);
		char_fill(str, 0, prm->width + 1, prm->c_fill, 1);
		if (prm->head)
			char_fill(str, 0, prm->width + 1, ' ', 1);
		str[prm->width] = '\0';
		if (!prm->head)
			str[prm->width - 1] = c;
		else
			str[0] = c;
		while (i < prm->width)
			ft_putchar(str[i++]);
		free(str);
	}
	else
		write(1, &c, 1);
}
