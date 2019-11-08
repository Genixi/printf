/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:45:29 by equiana           #+#    #+#             */
/*   Updated: 2019/11/08 18:39:11 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int ft_prm_parse(char *str, t_param *prm)
{
	int i;
	int j;
	char *s_width;
	char *s_prec;

	i = 0;
/*
** parse flags
*/
	if (str[i] == '-' || str[i] == '+' || str[i] == ' ' || str[i] == '#' || str[i] == '0')
		prm->flag = str[i++];
/*
** parse width
*/
	if (str[i] <= '9' && str[i] >= '0')
	{
		j = 0;
		while (str[i + j] >= '0' && str[i + j] <= '9')
			j++;
		if (!(s_width = (char*)malloc(sizeof(char) * j)))
			ft_error(1);
		s_width[j] = '\0';
		j = 0;
		while (str[i + j] >= '0' && str[i + j] <= '9')
		{
			s_width[j] = str[j + i];
			j++;
		}
		i += j;
		prm->width = ft_atoi(s_width);
		free(s_width);		
	}
/*
** parse precision
*/
	if (str[i] == '.')
	{
		i++;
		j = 0;
		while (str[i + j] >= '0' && str[i + j] <= '9')
			j++;
		if (!(s_prec = (char*)malloc(sizeof(char) * j)))
			ft_error(1);
		s_prec[j] = '\0';
		j = 0;
		while (str[i + j] >= '0' && str[i + j] <= '9')
		{
			s_prec[j] = str[j + i];
			j++;
		}
		i += j;
		prm->precision = ft_atoi(s_prec);
		free(s_prec);
	}
/*
** parse modificator
*/
	if (str[i] == 'h' || str[i] == 'l' || str[i] == 'L')
		prm->mod = str[i++];
/*
** parse type
*/
	if (str[i] == 'c' || str[i] == 's' || str[i] == 'd' || str[i] == 'i' || str[i] == 'f')
		prm->type = str[i++];
	else if (str[i] == 'u' || str[i] == 'F' || str[i] == 'e' || str[i] == 'g' || str[i] == 'G')
		prm->type = str[i++];
	else if (str[i] == 'o' || str[i] == 'x' || str[i] == 'X' || str[i] == '%')
		prm->type = str[i++];
	if (!i)
		ft_error(2);
	return (i);
}

void ft_prm_init(t_param *p)
{
	p->flag = 'Z';
	p->width = -1;
	p->precision = -1;
	p->mod = 'Z';
	p->type = 'Z';
}
