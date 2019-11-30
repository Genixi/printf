/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 22:00:11 by equiana           #+#    #+#             */
/*   Updated: 2019/11/30 15:51:02 by equiana          ###   ########.fr       */
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

int get_num_len(long int n)
{
	int size;

	size = 0;
	if (n < 0)
		n = n * -1;
	while (n)
	{
		if (n /= 10)
			size++;
	}
	size++;
	return (size);
}

double ft_power(double n, int pow)
{
	return (pow ? n * ft_power(n, pow - 1) : 1);
}

void char_fill_0(char *str, int start, int end, char c)
{
	int i;

	i = start;
	while (i < end)
		str[i++] = c;
}

void char_fill_eof(char *str, int start, int end, char c)
{
	int i;

	i = start;
	while (i < end)
		str[i++] = c;
	str[end - 1] = '\0';
}

void	char_fill(char *str, int start, int end, char c, int eof)
{
	int i;

	i = start;
	while (i < end)
		str[i++] = c;
	if (eof)
		str[end - 1] = '\0';
}
