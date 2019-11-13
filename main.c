/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:58:54 by equiana           #+#    #+#             */
/*   Updated: 2019/11/13 17:37:03 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int main() {
	int res;

	printf("\nnumbers\n");
	printf("printf    int 1: %d and go ahead\n", 21);
	res = ft_printf("ft_printf int 1: %d and go ahead\n", 21);
	
	printf("printf    int 2: %d and go ahead\n", -21234);
	res = ft_printf("ft_printf int 2: %d and go ahead\n", -21234);

	printf("printf    int 3: %5i and go ahead\n", 21234);
	res = ft_printf("ft_printf int 3: %5i and go ahead\n", 21234);
	
	printf("printf    int 4: %5.10d and go ahead\n", 21);
	res = ft_printf("ft_printf int 4: %5.10d and go ahead\n", 21);
	
	printf("printf    int 5: %5.7i and go ahead\n", -21);
	res = ft_printf("ft_printf int 5: %5.7i and go ahead\n", -21);
	
	printf("printf    int 6: %3.7d and go ahead\n", -21234);
	res = ft_printf("ft_printf int 6: %3.7d and go ahead\n", -21234);
	
	printf("printf    int 7: %3i and go ahead\n", 21234);
	res = ft_printf("ft_printf int 7: %3i and go ahead\n", 21234);

	printf("printf    int 8: %7.3d and go ahead\n", -21234);
	res = ft_printf("ft_printf int 8: %7.3d and go ahead\n", -21234);
	
	printf("printf    unsigned int 8: %5u and go ahead\n", 2147483647);
	res = ft_printf("ft_printf unsigned int 8: %5u and go ahead\n", 2147483647);
	
	printf("printf    unsigned int 9: %15.5u and go ahead\n", 2147483647);
	res = ft_printf("ft_printf unsigned int 9: %15.5u and go ahead\n", 2147483647);
	
	printf("printf    unsigned int 10: %13.20u and go ahead\n", 2147483647);
	res = ft_printf("ft_printf unsigned int 10: %13.20u and go ahead\n", 2147483647);

	printf("printf    unsigned int 11: %13.20u and go ahead\n", -2147483647);
	res = ft_printf("ft_printf unsigned int 11: %13.20u and go ahead\n", -2147483647);

	printf("printf    unsigned int 12: %3.2u and go ahead\n", -2147483647);
	res = ft_printf("ft_printf unsigned int 12: %3.2u and go ahead\n", -2147483647);

	printf("printf    long int 13: %3.2li and go ahead\n", 4000000000);
	res = ft_printf("ft_printf long int 13: %3.2li and go ahead\n", 4000000000);

	printf("printf    long int 14: %13.2ld and go ahead\n", 4300000000);
	res = ft_printf("ft_printf long int 14: %13.2ld and go ahead\n", 4300000000);	

	printf("printf    long int 15: %3.12li and go ahead\n", 9300000000);
	res = ft_printf("ft_printf long int 15: %3.12li and go ahead\n", 9300000000);	
	
	printf("itoa_li test 1: %s\n", ft_itoa_base_li(9300000000, 10, 0));
	printf("itoa_li test 2: %s\n", ft_itoa_base_li(4300000000, 10, 0));
    
    printf("printf    short int 13: %3.2hi and go ahead\n", (short int)30700);
    res = ft_printf("ft_printf short int 13: %3.2hi and go ahead\n", 30700);
    
    printf("printf    short int 14: %13.2hd and go ahead\n", (short int)-30700);
    res = ft_printf("ft_printf short int 14: %13.2hd and go ahead\n", -30700);
    
    printf("printf    short int 15: %3.12hi and go ahead\n", (short int)-9123);
    res = ft_printf("ft_printf short int 15: %3.12hi and go ahead\n", -9123);
    
/*
    printf("-------------------------------------------------\n");
    printf("octet type\n");
    printf("printf    octet 1: %o and go ahead\n", 21);
    res = ft_printf("ft_printf octet 1: %o and go ahead\n", 21);

    printf("printf    octet 2: %o and go ahead\n", -21234);
    res = ft_printf("ft_printf octet 2: %o and go ahead\n", -21234);

    printf("printf    octet 3: %5o and go ahead\n", 21234);
    res = ft_printf("ft_printf octet 3: %5o and go ahead\n", 21234);

    printf("printf    octet 4: %5.10o and go ahead\n", 21);
    res = ft_printf("ft_printf octet 4: %5.10o and go ahead\n", 21);

    printf("printf    octet 5: %5.7o and go ahead\n", -21);
    res = ft_printf("ft_printf octet 5: %5.7o and go ahead\n", -21);

    printf("printf    octet 6: %3.7o and go ahead\n", -21234);
    res = ft_printf("ft_printf octet 6: %3.7o and go ahead\n", -21234);

    printf("printf    octet 7: %3o and go ahead\n", 21234);
    res = ft_printf("ft_printf octet 7: %3o and go ahead\n", 21234);

    printf("printf    octet 8: %5o and go ahead\n", 2147483647);
    res = ft_printf("ft_printf octet 8: %5o and go ahead\n", 2147483647);

    printf("printf    octet 9: %15.5o and go ahead\n", 2147483647);
    res = ft_printf("ft_printf octet 9: %15.5o and go ahead\n", 2147483647);

    printf("printf    octet 10: %13.20o and go ahead\n", 2147483647);
    res = ft_printf("ft_printf octet 10: %13.20o and go ahead\n", 2147483647);

    printf("printf    octet 11: %13.20o and go ahead\n", -2147483647);
    res = ft_printf("ft_printf octet 11: %13.20o and go ahead\n", -2147483647);

	printf("printf    octet 12: %15.5o and go ahead\n", -214748);
	res = ft_printf("ft_printf octet 12: %15.5o and go ahead\n", -214748);
    
    printf("-------------------------------------------------\n");
    printf("hex type\n");
    printf("printf    hex 1: %x and go ahead\n", 21);
    res = ft_printf("ft_printf hex 1: %x and go ahead\n", 21);
    
    printf("printf    hex 2: %x and go ahead\n", -21234);
    res = ft_printf("ft_printf hex 2: %x and go ahead\n", -21234);
    
    printf("printf    hex 3: %5x and go ahead\n", 21234);
    res = ft_printf("ft_printf hex 3: %5x and go ahead\n", 21234);
    
    printf("printf    hex 4: %5.10x and go ahead\n", 21);
    res = ft_printf("ft_printf hex 4: %5.10x and go ahead\n", 21);
    
    printf("printf    hex 5: %5.7x and go ahead\n", -21);
    res = ft_printf("ft_printf hex 5: %5.7x and go ahead\n", -21);
    
    printf("printf    hex 6: %3.7x and go ahead\n", -21234);
    res = ft_printf("ft_printf hex 6: %3.7x and go ahead\n", -21234);
    
    printf("printf    hex 7: %3x and go ahead\n", 21234);
    res = ft_printf("ft_printf hex 7: %3x and go ahead\n", 21234);
    
    printf("printf    hex 8: %5x and go ahead\n", 2147483647);
    res = ft_printf("ft_printf hex 8: %5x and go ahead\n", 2147483647);
    
    printf("printf    hex 9: %15.5x and go ahead\n", 2147483647);
    res = ft_printf("ft_printf hex 9: %15.5x and go ahead\n", 2147483647);
    
    printf("printf    hex 10: %13.20x and go ahead\n", 2147483647);
    res = ft_printf("ft_printf hex 10: %13.20x and go ahead\n", 2147483647);
    
    printf("printf    hex 11: %13.20x and go ahead\n", -2147483647);
    res = ft_printf("ft_printf hex 11: %13.20x and go ahead\n", -2147483647);
    
    printf("printf    hex 12: %15.5x and go ahead\n", -214748);
    res = ft_printf("ft_printf hex 12: %15.5x and go ahead\n", -214748);

	printf("printf    hex 13: %13.20X and go ahead\n", 2147483647);
	res = ft_printf("ft_printf hex 13: %13.20X and go ahead\n", 2147483647);

	printf("printf    hex 14: %13.20X and go ahead\n", -2147483647);
	res = ft_printf("ft_printf hex 11: %13.20X and go ahead\n", -2147483647);

	printf("printf    hex 15: %15.5X and go ahead\n", -214748);
	res = ft_printf("ft_printf hex 15: %15.5X and go ahead\n", -214748);

    int *int_ptr;
	char *char_ptr;
	char str_ptr[4] = "test";
	int i;
	char c;

	i = 21;
	res = i;
	c = 'Z';
	int_ptr = &i;
	char_ptr = &c;
	printf("printf    pointer int 1: %20p\n", int_ptr);
	res = ft_printf("ft_printf pointer int 1: %20p\n", int_ptr);
	
	printf("printf    pointer char 2: %20p\n", char_ptr);
	res = ft_printf("ft_printf pointer char 2: %20p\n", char_ptr);

	printf("printf    pointer char 3: %20p\n", str_ptr);
	res = ft_printf("ft_printf pointer char 3: %20p\n", str_ptr);

	printf("----------------------------------------------------------------\n");
	printf("\nchar\n");
	printf("printf    char 1: %10c and go ahead\n", 'A');
   	res = ft_printf("ft_printf char 1: %10c and go ahead\n", 'A');
	
	printf("printf    char 1: %3c and go ahead\n", 'z');
	res = ft_printf("ft_printf char 1: %3c and go ahead\n", 'z');
	
	printf("\nstring\n");
	printf("printf    string 1: %13.5s and go ahead\n", "Test_strinG");
	res = ft_printf("ft_printf string 1: %13.5s and go ahead\n", "Test_strinG");

	printf("printf    string 2: %5.13s and go ahead\n", "Test strinG");
	res = ft_printf("ft_printf string 2: %5.13s and go ahead\n", "Test strinG");

	printf("printf    string 3: %20.15s and go ahead\n", "Test strinG");
	res = ft_printf("ft_printf string 3: %20.15s and go ahead\n", "Test strinG");

	printf("printf    string 4: %3.5s and go ahead\n", "Test_strinG");
	res = ft_printf("ft_printf string 4: %3.5s and go ahead\n", "Test_strinG");

	printf("printf    string 5: %3.0s and go ahead\n", "Test_strinG");
	res = ft_printf("ft_printf string 5: %3.0s and go ahead\n", "Test_strinG");

//	res = ft_printf("test parse 1: %13s\n", "test");

//	res = ft_printf("test parse 2: %04.4x\n", "test");

//	res = ft_printf("test parse 8: %.5s\n", "test");

//	res = ft_printf("test parse 20: %-5s\n", "ab");


	
	printf("------------------------------------------------------------------\n");
	printf("float, double\n");
	printf("printf    double 1: %.5f and go on\n", 771.83335);
	res = ft_printf("ft_printf double 1: %.5f and go on\n", 771.83335);
	
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

	printf("printf    double 11: %5.1f\n", 2.7182818);
	res = ft_printf("ft_printf double 11: %5.1f\n", 2.7182818);

	printf("printf    double 12: %7.2f\n", -783.234);
	res = ft_printf("ft_printf double 12: %7.2f\n", -783.234);

//	res = ft_printf("test parse 24: %+-5.1f\n", 2.7182818);
//	res = ft_printf("test parse 9: %0*.*f\n", 771.833);


//	res = ft_printf("test parse 3: %0*.*x\n", "test");
//	res = ft_printf("test parse 5: %.60g\n", "test");
*/
	return (0);
}
