/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:13:07 by equiana           #+#    #+#             */
/*   Updated: 2019/11/11 19:52:30 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

int ft_printf(const char *restrict format, ...)
{
    char *str;
    int res;
	t_param prm;

	ft_prm_init(&prm);
	va_list ap;
    va_start(ap, format);
    res = 0;
    str = (char*)format;
    while (*str)
    {
        if (*str == '%')
        {
            str++;
			res = ft_prm_parse(str, &prm);
			ft_display(ap, &prm);
//			resume in production
//			ft_prm_init(&prm);
			str += res - 1;
  		}
        else
            write(1, str, 1);
        str++;
    }
//	printf("parameters: ");
//	display_str(&prm);
//	printf("\n");
//	printf(" res: %d\n", res);
    va_end(ap);
//	free(str);
//  очистить структуру
	return (res);
}

