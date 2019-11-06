/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:58:54 by equiana           #+#    #+#             */
/*   Updated: 2019/11/07 00:21:10 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int main() {
    int res;
    int i;
    char c;
    char str[] = "test";
    unsigned int u;
    
    i = 1;
    c = 'A';
    u = 4000000000;
    res = ft_printf("integer: %d\n", i);
    res = ft_printf("char: %c\n", c);
    res = ft_printf("string: %s\n", str);
    res = ft_printf("unsigned: %u\n", u);
	res = ft_printf("double_1: %f\n", 771.83335);
	res = ft_printf("double_2: %f\n", -783.234);
	res = ft_printf("double_3: %f\n", 0.385);
	res = ft_printf("double_4: %f\n", 11111.11111);
    res = ft_printf("double_5: %f\n", 00.385);
	res = ft_printf("double_6: %f\n", 24.00385);
	return 0;
}
