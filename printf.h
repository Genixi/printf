/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:59:58 by equiana           #+#    #+#             */
/*   Updated: 2019/11/06 22:00:00 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRINTF_H
#define FT_PRINTF_PRINTF_H

#include <stdarg.h>
#include "libft.h"

typedef struct    s_param
{
    char        flag;
    char        width;
    int        precision;
    char        mod;
    char        spec;
}                t_param;

int        ft_printf(const char *restrict format, ...);
void    ft_putnbr_u(unsigned int n);
void    ft_putnbr_f(double n, t_param *p);
void    ft_error(int n);

#endif //FT_PRINTF_PRINTF_H
