/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:58:54 by equiana           #+#    #+#             */
/*   Updated: 2019/11/08 18:58:19 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int main() {
	int res;

	res = ft_printf("test int 1: %d and go ahead\n", 21);
	printf("parameters: flag: Z width: -1 precision: -1 modificator: Z type: d\n");
	res = ft_printf("test char 1: %c\n", 'A');
	printf("parameters: flag: Z width: -1 precision: -1 modificator: Z type: c\n");
	res = ft_printf("test string 1: %s\n", "test");
	printf("parameters: flag: Z width: -1 precision: -1 modificator: Z type: s\n");
    res = ft_printf("test unsigned 1: %u\n", 4000000000);
	printf("parameters: flag: Z width: -1 precision: -1 modificator: Z type: u\n");
	res = ft_printf("double 1: %.5f\n", 771.83335);
	printf("parameters: flag: Z width: -1 precision: 5 modificator: Z type: f\n");
	res = ft_printf("double 2: %.3f\n", -783.234);
	printf("parameters: flag: Z width: -1 precision: 3 modificator: Z type: f\n");
	res = ft_printf("double 3: %.3f\n", 0.385);
	printf("parameters: flag: Z width: -1 precision: 3 modificator: Z type: f\n");
	res = ft_printf("double 4: %.5f\n", 11111.11111);
	printf("parameters: flag: Z width: -1 precision: 5 modificator: Z type: f\n");
    res = ft_printf("double 5: %.3f\n", 00.385);
	printf("parameters: flag: Z width: -1 precision: 3 modificator: Z type: f\n");
	res = ft_printf("double 6: %.5f\n", 24.00385);
	printf("parameters: flag: Z width: -1 precision: 5 modificator: Z type: f\n");
	res = ft_printf("test parse 1: %13s\n", "test");
	printf("parameters: flag: Z width: 13 precision: -1 modificator: Z type: s\n");
	res = ft_printf("test parse 2: %04.4x\n", "test");
	printf("parameters: flag: 0 width: 4 precision: 4 modificator: Z type: x\n");
//	res = ft_printf("test parse 3: %0*.*x\n", "test");
	res = ft_printf("test parse 4: %010ld\n", 40000000000000);
	printf("parameters: flag: 0 width: 10 precision: -1 modificator: l type: d\n");
	res = ft_printf("test parse 5: %.60g\n", "test");
	printf("parameters: flag: Z width: -1 precision: 60 modificator: Z type: g\n");
	res = ft_printf("test parse 6: %12.4f\n", 771.833);
	printf("parameters: flag: Z width: 12 precision: 4 modificator: Z type: f\n");
	res = ft_printf("test parse 7: %010.2lf\n", 771.833);
	printf("parameters: flag: 0 width: 10 precision: 2 modificator: l type: f\n");
	res = ft_printf("test parse 8: %.5s\n", "test");
	printf("parameters: flag: Z width: -1 precision: 5 modificator: Z type: s\n");
//	res = ft_printf("test parse 9: %0*.*f\n", 771.833);	
	res = ft_printf("test parse 10: %-6d\n", 7);
	printf("parameters: flag: - width: 6 precision: -1 modificator: Z type: d\n");
	res = ft_printf("test parse 11: %+6d\n", 7);
	printf("parameters: flag: + width: 6 precision: -1 modificator: Z type: d\n");
	res = ft_printf("test parse 12: %lu\n", 4000000000);
	printf("parameters: flag: Z width: -1 precision: -1 modificator: l type: u\n");	
	res = ft_printf("test parse 13: %5d\n", 77);
	printf("parameters: flag: Z width: 5 precision: -1 modificator: Z type: d\n");
	res = ft_printf("test parse 14: %-5d\n", 77);
	printf("parameters: flag: - width: 5 precision: -1 modificator: Z type: d\n");
	res = ft_printf("test parse 15: %05d\n", 77);
	printf("parameters: flag: 0 width: 5 precision: -1 modificator: Z type: d\n");
	res = ft_printf("test parse 16: %+5d\n", 77);
	printf("parameters: flag: + width: 5 precision: -1 modificator: Z type: d\n");
	res = ft_printf("test parse 17: % 5d\n", 77);
	printf("parameters: flag:   width: 5 precision: -1 modificator: Z type: d\n");
//	res = ft_printf("test parse 18: % 05d\n", 77);
	res = ft_printf("test parse 19: %5s\n", "ab");
	printf("parameters: flag: Z width: 5 precision: -1 modificator: Z type: s\n");
	res = ft_printf("test parse 20: %-5s\n", "ab");
	printf("parameters: flag: - width: 5 precision: -1 modificator: Z type: s\n");
	res = ft_printf("test parse 21: %.7f\n", 2.7182818);
	printf("parameters: flag: Z width: -1 precision: 7 modificator: Z type: f\n");
	res = ft_printf("test parse 22: %5.0f\n", 2.7182818);
	printf("parameters: flag: Z width: 5 precision: 0 modificator: Z type: f\n");
	res = ft_printf("test parse 23: %05.1f\n", 2.7182818);
	printf("parameters: flag: 0 width: 5 precision: 1 modificator: Z type: f\n");
//	res = ft_printf("test parse 24: %+-5.1f\n", 2.7182818);
	return 0;
}
