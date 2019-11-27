/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:45:29 by equiana           #+#    #+#             */
/*   Updated: 2019/11/27 16:19:45 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>
#include <stdio.h>

void set_param(t_param *prm)
{
//	printf("set params");
	prm->hash = (prm->flag == '#' || prm->flag_2 == '#' || prm->flag_3 == '#') ? 1 : 0;
	prm->space = (prm->flag == ' ' || prm->flag_2 == ' ' || prm->flag_3 == ' ') ? 1 : 0;
	prm->plus = (prm->flag == '+' || prm->flag_2 == '+' || prm->flag_3 == '+') ? 1 : 0;
	prm->null = (prm->flag == '0' || prm->flag_2 == '0' || prm->flag_3 == '0') ? 1 : 0;
	prm->head = (prm->flag == '-' || prm->flag_2 == '-' || prm->flag_3 == '-') ? 1 : 0;
}

int ft_prm_parse(char *str, t_param *prm)
{
	int i;
	int j;
	char *s_width;
	char *s_prec;

//	printf(" !!case parse!! ");
	i = 0;

/*
**parse %
*/
//	if (str[i] == '%')
//	{
//		prm->type = '%';
//		return (1);
//	}
	
/*
** parse flags
*/
	if (str[i] == '-' || str[i] == '+' || str[i] == ' ' || str[i] == '#' || str[i] == '0')
		prm->flag = str[i++];
	if (str[i] == '-' || str[i] == '+' || str[i] == ' ' || str[i] == '#' || str[i] == '0')
		prm->flag_2 = str[i++];
	if (str[i] == '-' || str[i] == '+' || str[i] == ' ' || str[i] == '#' || str[i] == '0')
		prm->flag_3 = str[i++];
	if (str[i] == '-' || str[i] == '+' || str[i] == ' ' || str[i] == '#' || str[i] == '0')
	{
		if (str[i] == '+')
		{
			if (prm->flag == ' ')
				prm->flag = '+';
			else if (prm->flag_2 == ' ')
				prm->flag_2 = '+';
			else if (prm->flag_3 == ' ')
				prm->flag_3 = '+';
		}
		else if (str[i] == '-')
		{
			if (prm->flag == '0')
				prm->flag = '-';
			else if (prm->flag_2 == '0')
				prm->flag_2 = '-';
			else if (prm->flag_3 == '0')
				prm->flag_3 = '-';
		}
		i++;
	}
	
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
		if (!j)
			prm->precision = 0;
		else 
		{
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
	}
/*
** parse modificator
*/
	if (str[i] == 'h' || str[i] == 'l' || str[i] == 'L')
		prm->mod = str[i++];
	if (str[i] == 'h' || str[i] == 'l')
		prm->mod_2 = str[i++];
/*
** parse type
*/
	if (str[i] == 'c' || str[i] == 's' || str[i] == 'd' || str[i] == 'i' || str[i] == 'f' || str[i] == 'p')
		prm->type = str[i++];
	else if (str[i] == 'u' || str[i] == 'F' || str[i] == 'e' || str[i] == 'g' || str[i] == 'G')
		prm->type = str[i++];
	else if (str[i] == 'o' || str[i] == 'x' || str[i] == 'X' || str[i] == '%')
		prm->type = str[i++];
	if (!i)
		ft_error(2);

	set_param(prm);
	return (i);
}

void ft_prm_init(t_param *p)
{
	p->flag = 'Z';
	p->flag_2 = 'Z';
	p->flag_3 = 'Z';
	p->width = -1;
	p->precision = -1;
	p->mod = 'Z';
	p->mod_2 = 'Z';
	p->type = 'Z';
}
