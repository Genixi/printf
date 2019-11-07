/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 22:00:11 by equiana           #+#    #+#             */
/*   Updated: 2019/11/07 20:19:12 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <stdio.h>
void ft_error(int n)
{
    if (n == 1)
        ft_putstr("malloc error\n");
    exit(0);
}

void display_str(t_param *prm)
{
	printf("flag: %c ", prm->flag);
	printf("width: %d ", prm->width);
	printf("precision: %d ", prm->precision);
	printf("type: %s", prm->type);	
}

