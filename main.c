/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:58:54 by equiana           #+#    #+#             */
/*   Updated: 2019/11/11 20:54:04 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int main() {
	int res;

/*	
	printf("\nnumbers\n");
	printf("printf    int 1: %d and go ahead\n", 21);
	res = ft_printf("ft_printf int 1: %d and go ahead\n", 21);
	printf("parameters: flag: Z width: -1 precision: -1 modificator: Z type: d\n");
	
	printf("printf    int 2: %d and go ahead\n", -21234);
	res = ft_printf("ft_printf int 2: %d and go ahead\n", -21234);
	printf("parameters: flag: Z width: -1 precision: -1 modificator: Z type: d\n");

	printf("printf    int 3: %5i and go ahead\n", 21234);
	res = ft_printf("ft_printf int 3: %5i and go ahead\n", 21234);
	printf("parameters: flag: Z width: 5 precision: -1 modificator: Z type: i\n");
	
	printf("printf    int 4: %5.10d and go ahead\n", 21);
	res = ft_printf("ft_printf int 4: %5.10d and go ahead\n", 21);
	printf("parameters: flag: Z width: 5 precision: 10 modificator: Z type: d\n");
	
	printf("printf    int 5: %5.7i and go ahead\n", -21);
	res = ft_printf("ft_printf int 5: %5.7i and go ahead\n", -21);
	printf("parameters: flag: Z width: 5 precision: 7 modificator: Z type: i\n");
	
	printf("printf    int 6: %3.7d and go ahead\n", -21234);
	res = ft_printf("ft_printf int 6: %3.7d and go ahead\n", -21234);
	printf("parameters: flag: Z width: 3 precision: 3 modificator: Z type: d\n");
	
	printf("printf    int 7: %3i and go ahead\n", 21234);
	res = ft_printf("ft_printf int 7: %3i and go ahead\n", 21234);
	printf("parameters: flag: Z width: 3 precision: -1 modificator: Z type: i\n");

//	res = ft_printf("test parse 11: %+6d\n", 7);

	res = ft_printf("test parse 13: %5d\n", 77);

	res = ft_printf("test parse 10: %-6d\n", 7);

	res = ft_printf("test parse 14: %-5d\n", 77);

	res = ft_printf("test parse 15: %05d\n", 77);

	res = ft_printf("test parse 16: %+5d\n", 77);

	res = ft_printf("test parse 17: % 5d\n", 77);

//	res = ft_printf("test parse 18: % 05d\n", 77);

	res = ft_printf("test parse 19: %5s\n", "ab");

	res = ft_printf("test parse 4: %010ld\n", 40000000000000);


	printf("printf    unsigned int 8: %5u and go ahead\n", 2147483647);
	res = ft_printf("ft_printf unsigned int 8: %5u and go ahead\n", 2147483647);
	printf("parameters: flag: Z width: 5 precision: -1 modificator: Z type: u\n");
	
	printf("printf    unsigned int 9: %15.5u and go ahead\n", 2147483647);
	res = ft_printf("ft_printf unsigned int 9: %15.5u and go ahead\n", 2147483647);
	printf("parameters: flag: Z width: 15 precision: -1 modificator: Z type: u\n");
	
	printf("printf    unsigned int 10: %13.20u and go ahead\n", 2147483647);
	res = ft_printf("ft_printf unsigned int 10: %13.20u and go ahead\n", 2147483647);
	printf("parameters: flag: Z width: 13 precision: -1 modificator: Z type: u\n");

	printf("printf    unsigned int 11: %13.20u and go ahead\n", -2147483647);
	res = ft_printf("ft_printf unsigned int 11: %13.20u and go ahead\n", -2147483647);
	printf("parameters: flag: Z width: 13 precision: -1 modificator: Z type: u\n");

	printf("printf    unsigned int 12: %u\n", 4000000000);
	res = ft_printf("ft_printf    unsigned int 12: %u\n", 4000000000);
	printf("parameters: flag: Z width: -1 precision: -1 modificator: Z type: u\n");

	res = ft_printf("test parse 12: %lu\n", 4000000000);

	


	printf("----------------------------------------------------------------\n");
	printf("\nchar\n");
	printf("printf    char 1: %10c and go ahead\n", 'A');
   	res = ft_printf("ft_printf char 1: %10c and go ahead\n", 'A');
	printf("parameters: flag: Z width: 10 precision: -1 modificator: Z type: c\n");
	
	printf("printf    char 1: %3c and go ahead\n", 'z');
	res = ft_printf("ft_printf char 1: %3c and go ahead\n", 'z');
	printf("parameters: flag: Z width: 3 precision: -1 modificator: Z type: c\n");
	
	printf("\nstring\n");
	printf("printf    string 1: %13.5s and go ahead\n", "Test_strinG");
	res = ft_printf("ft_printf string 1: %13.5s and go ahead\n", "Test_strinG");
	printf("parameters: flag: Z width: 13 precision: 5 modificator: Z type: s\n");

	printf("printf    string 2: %5.13s and go ahead\n", "Test strinG");
	res = ft_printf("ft_printf string 2: %5.13s and go ahead\n", "Test strinG");
	printf("parameters: flag: Z width: 5 precision: 13 modificator: Z type: s\n");

	printf("printf    string 3: %20.15s and go ahead\n", "Test strinG");
	res = ft_printf("ft_printf string 3: %20.15s and go ahead\n", "Test strinG");
	printf("parameters: flag: Z width: 20 precision: 15 modificator: Z type: s\n");

	printf("printf    string 4: %3.5s and go ahead\n", "Test_strinG");
	res = ft_printf("ft_printf string 4: %3.5s and go ahead\n", "Test_strinG");
	printf("parameters: flag: Z width: 3 precision: 5 modificator: Z type: s\n");

	printf("printf    string 5: %3.0s and go ahead\n", "Test_strinG");
	res = ft_printf("ft_printf string 5: %3.0s and go ahead\n", "Test_strinG");
	printf("parameters: flag: Z width: 3 precision: 0 modificator: Z type: s\n");

	res = ft_printf("test parse 1: %13s\n", "test");

 	res = ft_printf("test parse 2: %04.4x\n", "test");

	res = ft_printf("test parse 8: %.5s\n", "test");

	res = ft_printf("test parse 20: %-5s\n", "ab");


*/	
	printf("------------------------------------------------------------------\n");
	printf("float, double\n");
	printf("printf    double 1: %.5f\n", 771.83335);
	res = ft_printf("ft_printf double 1: %.5f\n", 771.83335);
	
	printf("printf    double 2: %9.3f and go on\n", -783.234);
	res = ft_printf("ft_printf double 2: %9.3f and go on\n", -783.234);

	printf("printf    double 3: %.2f\n", 0.385);
	res = ft_printf("ft_printf double 3: %.2f\n", 0.385);

	printf("printf    double 4: %.6f\n", 11111.11111);	
	res = ft_printf("ft_printf double 4: %.6f\n", 11111.11111);
    
	printf("printf    double 5: %.3f and go on\n", 00.385);
	res = ft_printf("ft_printf double 5: %.3f and go on\n", 00.385);
	
	printf("printf    double 6: %3.6f\n", 24.00385);
	res = ft_printf("ft_printf double 6: %2.6f\n", 24.00385);

	printf("printf    double 7: %12.4f\n", 771.833);
	res = ft_printf("ft_printf double 7: %12.4f\n", 771.833);

//	printf("printf    double 8: %010.2lf\n", 771.833);
//	res = ft_printf("ft_printf double 8: %010.2lf\n", 771.833);

	printf("printf    double 9: %.7f\n", 2.7182818);
	res = ft_printf("ft_printf double 9: %.7f\n", 2.7182818);

	printf("printf    double 10: %5.0f\n", 2.7182818);
	res = ft_printf("ft_printf double 10: %5.0f\n", 2.7182818);

	printf("printf    double 11: %05.1f\n", 2.7182818);
	res = ft_printf("ft_printf double 11: %05.1f\n", 2.7182818);

	printf("printf    double 12: %7.2f\n", -783.234);
	res = ft_printf("ft_printf double 12: %7.2f\n", -783.234);

//	res = ft_printf("test parse 24: %+-5.1f\n", 2.7182818);
//	res = ft_printf("test parse 9: %0*.*f\n", 771.833);


//	res = ft_printf("test parse 3: %0*.*x\n", "test");
//	res = ft_printf("test parse 5: %.60g\n", "test");
	return 0;
}
