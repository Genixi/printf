/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:58:54 by equiana           #+#    #+#             */
/*   Updated: 2019/11/07 20:21:55 by equiana          ###   ########.fr       */
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
	res = ft_printf("test int 1: %d\n", i);
    res = ft_printf("test char 1: %c\n", c);
    res = ft_printf("test string 1: %s\n", str);
    res = ft_printf("test unsigned 1: %u\n", u);
	res = ft_printf("double 1: %f\n", 771.83335);
	res = ft_printf("double 2: %f\n", -783.234);
	res = ft_printf("double 3: %f\n", 0.385);
	res = ft_printf("double 4: %f\n", 11111.11111);
    res = ft_printf("double 5: %f\n", 00.385);
	res = ft_printf("double 6: %f\n", 24.00385);
	res = ft_printf("test parse 1: %13s\n", str);
	res = ft_printf("test parse 2: %04.4x\n", str);
//	res = ft_printf("test parse 3: %0*.*x\n", str);
	res = ft_printf("test parse 4: %010ld\n", str);
	res = ft_printf("test parse 5: %.60g\n", str);
	res = ft_printf("test parse 6: %12.4f\n", 771.833);
	res = ft_printf("test parse 7: %010.2lf\n", 771.833);
	res = ft_printf("test parse 8: %.5s\n", str);
//	res = ft_printf("test parse 9: %0*.*f\n", 771.833);	
	res = ft_printf("test parse 10: %-6d\n", 7);
	res = ft_printf("test parse 11: %+6d\n", 7);
	res = ft_printf("test parse 12: %llu\n", u);	
	res = ft_printf("test parse 13: %5d\n", 77);
	res = ft_printf("test parse 14: %-5d\n", 77);
	res = ft_printf("test parse 15: %05d\n", 77);
	res = ft_printf("test parse 16: %+5d\n", 77);
	res = ft_printf("test parse 17: % 5d\n", 77);
//	res = ft_printf("test parse 18: % 05d\n", 77);
	res = ft_printf("test parse 19: %5s\n", "ab");
	res = ft_printf("test parse 20: %-5s\n", "ab");
	res = ft_printf("test parse 21: %.7f\n", 2.7182818);
	res = ft_printf("test parse 22: %5.0f\n", 2.7182818);
	res = ft_printf("test parse 23: %05.1f\n", 2.7182818);
//	res = ft_printf("test parse 24: %+-5.1f\n", 2.7182818);
	return 0;
}
