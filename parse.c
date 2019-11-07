/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:45:29 by equiana           #+#    #+#             */
/*   Updated: 2019/11/07 20:21:52 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int ft_parse(char *str, t_param *prm)
{
	int i;
	int j;
	char *s_width;
	char *s_prec;
	char *s_type;

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
** parse type
*/
   j = (int)ft_strlen(str + i);
   if (!(s_type = (char*)malloc(sizeof(char) * j)))
	   ft_error(1);
   j = 0;
   while (str[i + j])
   {
	   s_type[j] = str[i + j];
	   j++;
   }
   s_type[j] = '\0';
   prm->type = s_type;
   return (i);
}
