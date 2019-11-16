/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:58:54 by equiana           #+#    #+#             */
/*   Updated: 2019/11/14 19:06:34 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int main() {
	int res;
/*
	printf("\ninteger\n");
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
 
    printf("printf    int 9: %20.13i and go ahead\n", 2147483647);
    res = ft_printf("ft_printf int 9: %20.13i and go ahead\n", 2147483647);
 
    printf("printf    int 10: %20.13i and go ahead\n", -2147483647);
    res = ft_printf("ft_printf int 10: %20.13i and go ahead\n", -2147483647);

	printf("printf    long int 1: %3.2li and go ahead\n", 4000000000);
	res = ft_printf("ft_printf long int 1: %3.2li and go ahead\n", 4000000000);

	printf("printf    long int 2: %13.2ld and go ahead\n", 4300000000);
	res = ft_printf("ft_printf long int 2: %13.2ld and go ahead\n", 4300000000);	

	printf("printf    long int 3: %3.12li and go ahead\n", 9300000000);
	res = ft_printf("ft_printf long int 3: %3.12li and go ahead\n", 9300000000);	
	
 	printf("printf    long int 4: %3.12li and go ahead\n", -9030100100);
	res = ft_printf("ft_printf long int 4: %3.12li and go ahead\n", -9030100100);

	printf("printf    long int 5: %13.2ld and go ahead\n", -4300000000);
	res = ft_printf("ft_printf long int 5: %13.2ld and go ahead\n", -4300000000);

    printf("printf    long long int 1: %3.2lli and go ahead\n", (long long)40100100100111222);
    res = ft_printf("ft_printf long long int 1: %3.2lli and go ahead\n", 40100100100111222);
    
    printf("printf    long long int 2: %13.2lld and go ahead\n", (long long)43100100100111222);
    res = ft_printf("ft_printf long long int 2: %13.2lld and go ahead\n", 43100100100111222);
    
    printf("printf    long long int 3: %3.12lli and go ahead\n", (long long)903100100100111222);
    res = ft_printf("ft_printf long long int 3: %3.12lli and go ahead\n", 903100100100111222);
    
	printf("printf    long long int 4: %3.2lli and go ahead\n", (long long)-40100100100111222);
	res = ft_printf("ft_printf long long int 4: %3.2lli and go ahead\n", -40100100100111222);

	printf("printf    long long int 5: %3.12lli and go ahead\n", (long long)-9030100100111222333);
	res = ft_printf("ft_printf long long int 5: %3.12lli and go ahead\n", -9030100100111222333);
    
    printf("printf    long long int 6: %3.12lli and go ahead\n", (long long)-9030100100111222333);
    res = ft_printf("ft_printf long long int 6: %3.12lli and go ahead\n", -9030100100111222333);

    printf("itoa_li test 1: %s\n", ft_itoa_base_li(9300000000111, 10, 0));
    printf("itoa_li test 2: %s\n", ft_itoa_base_li(4300000000111, 10, 0));

    printf("printf    short int 1: %3.2hi and go ahead\n", (short int)30700);
    res = ft_printf("ft_printf short int 1: %3.2hi and go ahead\n", 30700);
    
    printf("printf    short int 2: %13.2hd and go ahead\n", (short int)-30700);
    res = ft_printf("ft_printf short int 2: %13.2hd and go ahead\n", -30700);
    
    printf("printf    short int 3: %3.12hi and go ahead\n", (short int)-9123);
    res = ft_printf("ft_printf short int 3: %3.12hi and go ahead\n", -9123);

	printf("printf    short int 4: %hi and go ahead\n", (short int)-9123);
	res = ft_printf("ft_printf short int 4: %hi and go ahead\n", -9123);

	printf("printf    short int 5: %hd and go ahead\n", (short int)-30700);
	res = ft_printf("ft_printf short int 5: %hd and go ahead\n", -30700);

    printf("printf    short short int 1: %3.2hhi and go ahead\n", (signed char)126);
    res = ft_printf("ft_printf short short int 1: %3.2hhi and go ahead\n", 126);
    
    printf("printf    short short int 2: %13.2hhd and go ahead\n", (signed char)-120);
    res = ft_printf("ft_printf short short int 2: %13.2hhd and go ahead\n", -120);
    
    printf("printf    short short int 3: %3.12hhi and go ahead\n", (signed char)-128);
    res = ft_printf("ft_printf short short int 3: %3.12hhi and go ahead\n", -128);
    
    printf("printf    short short int 4: %hhi and go ahead\n", (signed char)-9123);
    res = ft_printf("ft_printf short short int 4: %hhi and go ahead\n", -9123);
    
    printf("printf    short short int 5: %hhd and go ahead\n", (signed char)-30700);
    res = ft_printf("ft_printf short short int 5: %hhd and go ahead\n", -30700);

	printf("printf    short short int 6: %hhd and go ahead\n", (signed char)127);
	res = ft_printf("ft_printf short short int 4: %hhd and go ahead\n", 127);


    printf("\n-------------------------------------------------\n");
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
 
    printf("printf    octet 13: %20.13o and go ahead\n", 2147483647);
    res = ft_printf("ft_printf octet 13: %20.13o and go ahead\n", 2147483647);
 
    printf("printf    octet 14: %20.13o and go ahead\n", -2147483647);
    res = ft_printf("ft_printf octet 14: %20.13o and go ahead\n", -2147483647);

    printf("printf    long octet 1: %2.13lo and go ahead\n", 4000000000);
    res = ft_printf("ft_printf long octet 1: %2.13lo and go ahead\n", 4000000000);
    
    printf("printf    long octet 2: %13.2lo and go ahead\n", 4300000000);
    res = ft_printf("ft_printf long octet 2: %13.2lo and go ahead\n", 4300000000);
    
    printf("printf    long octet 3: %3.12lo and go ahead\n", 9300000000);
    res = ft_printf("ft_printf long octet 3: %3.12lo and go ahead\n", 9300000000);  
  
    printf("printf    long octet 4: %3.12lo and go ahead\n", -9030100100);
    res = ft_printf("ft_printf long octet 4: %3.12lo and go ahead\n", -9030100100);
    
    printf("printf    long octet 5: %13.2lo and go ahead\n", -4300000000);
    res = ft_printf("ft_printf long octet 5: %13.2lo and go ahead\n", -4300000000);

    printf("printf    long long octet 1: %3.2llo and go ahead\n", (long long)40100100100111222);
    res = ft_printf("ft_printf long long octet 1: %3.2llo and go ahead\n", 40100100100111222);
    
    printf("printf    long long octet 2: %13.2llo and go ahead\n", (long long)43100100100111222);
    res = ft_printf("ft_printf long long octet 2: %13.2llo and go ahead\n", 43100100100111222);
    
    printf("printf    long long octet 3: %3.12llo and go ahead\n", (long long)903100100100111222);
    res = ft_printf("ft_printf long long octet 3: %3.12llo and go ahead\n", 903100100100111222);
    
    printf("printf    long long octet 4: %3.2llo and go ahead\n", (long long)-40100100100111222);
    res = ft_printf("ft_printf long long octet 4: %3.2llo and go ahead\n", -40100100100111222);
    
    printf("printf    long long octet 5: %3.12llo and go ahead\n", (long long)-9030100100111222333);
    res = ft_printf("ft_printf long long octet 5: %3.12llo and go ahead\n", -9030100100111222333);

    printf("printf    short octet 1: %3.2ho and go ahead\n", (short int)30700);
    res = ft_printf("ft_printf short octet 1: %3.2ho and go ahead\n", 30700);
    
    printf("printf    short octet 2: %13.2ho and go ahead\n", (short int)-30700);
    res = ft_printf("ft_printf short octet 2: %13.2ho and go ahead\n", -30700);
    
    printf("printf    short octet 3: %3.12ho and go ahead\n", (short int)-9123);
    res = ft_printf("ft_printf short octet 3: %3.12ho and go ahead\n", -9123);
    
    printf("printf    short octet 4: %ho and go ahead\n", (short int)-9123);
    res = ft_printf("ft_printf short octet 4: %ho and go ahead\n", -9123);
    
    printf("printf    short octet 5: %ho and go ahead\n", (short int)-30700);
    res = ft_printf("ft_printf short octet 5: %ho and go ahead\n", -30700);
 
    printf("printf    short short octet 1: %3.2hho and go ahead\n", (signed char)126);
    res = ft_printf("ft_printf short short octet 1: %3.2hho and go ahead\n", 126);
    
    printf("printf    short short octet 2: %13.2hho and go ahead\n", (signed char)-120);
    res = ft_printf("ft_printf short short octet 2: %13.2hho and go ahead\n", -120);
    
    printf("printf    short short octet 3: %3.12hho and go ahead\n", (signed char)-128);
    res = ft_printf("ft_printf short short octet 3: %3.12hho and go ahead\n", -128);
    
    printf("printf    short short octet 4: %hho and go ahead\n", (signed char)-9123);
    res = ft_printf("ft_printf short short octet 4: %hho and go ahead\n", -9123);
    
    printf("printf    short short octet 5: %hho and go ahead\n", (signed char)-30700);
    res = ft_printf("ft_printf short short octet 5: %hho and go ahead\n", -30700);
    
    printf("printf    short short octet 6: %hho and go ahead\n", (signed char)127);
    res = ft_printf("ft_printf short short octet 4: %hho and go ahead\n", 127);
  

    printf("\n-------------------------------------------------\n");
    printf("unsigned type\n");
    printf("printf    unsigned int 1: %5u and go ahead\n", 2147483647);
    res = ft_printf("ft_printf unsigned int 1: %5u and go ahead\n", 2147483647);
    
    printf("printf    unsigned int 2: %15.5u and go ahead\n", 2147483647);
    res = ft_printf("ft_printf unsigned int 2: %15.5u and go ahead\n", 2147483647);
    
    printf("printf    unsigned int 3: %13.20u and go ahead\n", 2147483647);
    res = ft_printf("ft_printf unsigned int 3: %13.20u and go ahead\n", 2147483647);
    
    printf("printf    unsigned int 4: %13.20u and go ahead\n", -2147483647);
    res = ft_printf("ft_printf unsigned int 4: %13.20u and go ahead\n", -2147483647);
    
    printf("printf    unsigned int 5: %3.2u and go ahead\n", -2147483647);
    res = ft_printf("ft_printf unsigned int 5: %3.2u and go ahead\n", -2147483647);
    
    printf("printf    unsigned int 6: %3.7u and go ahead\n", -21234);
    res = ft_printf("ft_printf unsigned int 6: %3.7u and go ahead\n", -21234);
    
    printf("printf    unsigned int 7: %3u and go ahead\n", 21234);
    res = ft_printf("ft_printf unsigned int 7: %3u and go ahead\n", 21234);
    
    printf("printf    unsigned int 8: %5u and go ahead\n", 2147483647);
    res = ft_printf("ft_printf unsigned int 8: %5u and go ahead\n", 2147483647);
    
    printf("printf    unsigned int 9: %15.5u and go ahead\n", 2147483647);
    res = ft_printf("ft_printf unsigned int 9: %15.5u and go ahead\n", 2147483647);
    
    printf("printf    unsigned int 10: %13.20u and go ahead\n", 2147483647);
    res = ft_printf("ft_printf unsigned int 10: %13.20u and go ahead\n", 2147483647);
    
    printf("printf    unsigned int 11: %13.20u and go ahead\n", -2147483647);
    res = ft_printf("ft_printf unsigned int 11: %13.20u and go ahead\n", -2147483647);
    
    printf("printf    unsigned int 12: %15.5u and go ahead\n", -214748);
    res = ft_printf("ft_printf unsigned int 12: %15.5u and go ahead\n", -214748);
 
    printf("printf    unsigned int 13: %20.13u and go ahead\n", 2147483647);
    res = ft_printf("ft_printf unsigned int 13: %20.13u and go ahead\n", 2147483647);
 
    printf("printf    unsigned int 14: %20.13u and go ahead\n", -2147483647);
    res = ft_printf("ft_printf unsigned int 14: %20.13u and go ahead\n", -2147483647);
 
    printf("printf    long unsigned int 1: %2.13lu and go ahead\n", 4000000000);
    res = ft_printf("ft_printf long unsigned int 1: %2.13lu and go ahead\n", 4000000000);
    
    printf("printf    long unsigned int 2: %13.2lu and go ahead\n", 4300000000);
    res = ft_printf("ft_printf long unsigned int 2: %13.2lu and go ahead\n", 4300000000);
    
    printf("printf    long unsigned int 3: %3.12lu and go ahead\n", 9300000000);
    res = ft_printf("ft_printf long unsigned int 3: %3.12lu and go ahead\n", 9300000000);
    
    printf("printf    long unsigned int 4: %3.12lu and go ahead\n", -9030100100);
    res = ft_printf("ft_printf long unsigned int 4: %3.12lu and go ahead\n", -9030100100);
    
    printf("printf    long unsigned int 5: %13.2lu and go ahead\n", -4300000000);
    res = ft_printf("ft_printf long unsigned int 5: %13.2lu and go ahead\n", -4300000000);
    
    printf("printf    long long unsigned int 1: %3.2llu and go ahead\n", (long long)40100100100111222);
    res = ft_printf("ft_printf long long unsigned int 1: %3.2llu and go ahead\n", 40100100100111222);
    
    printf("printf    long long unsigned int 2: %13.2llu and go ahead\n", (long long)43100100100111222);
    res = ft_printf("ft_printf long long unsigned int 2: %13.2llu and go ahead\n", 43100100100111222);
    
    printf("printf    long long unsigned int 3: %3.12llu and go ahead\n", (long long)903100100100111222);
    res = ft_printf("ft_printf long long unsigned int 3: %3.12llu and go ahead\n", 903100100100111222);
    
    printf("printf    long long unsigned int 4: %3.2llu and go ahead\n", (long long)-40100100100111222);
    res = ft_printf("ft_printf long long unsigned int 4: %3.2llu and go ahead\n", -40100100100111222);
    
    printf("printf    long long unsigned int 5: %3.12llu and go ahead\n", (long long)-9030100100111222333);
    res = ft_printf("ft_printf long long unsigned int 5: %3.12llu and go ahead\n", -9030100100111222333);
    
    printf("printf    long long unsigned int 6: %3.12llu and go ahead\n", (long long)-9030100100);
    res = ft_printf("ft_printf long long unsigned int 6: %3.12llu and go ahead\n", -9030100100);
    
    printf("printf    short unsigned int 1: %3.2hu and go ahead\n", (short int)30700);
    res = ft_printf("ft_printf short unsigned int 1: %3.2hu and go ahead\n", 30700);
    
    printf("printf    short unsigned int 2: %13.2hu and go ahead\n", (short int)-30700);
    res = ft_printf("ft_printf short unsigned int 2: %13.2hu and go ahead\n", -30700);
    
    printf("printf    short unsigned int 3: %3.12hu and go ahead\n", (short int)-9123);
    res = ft_printf("ft_printf short unsigned int 3: %3.12hu and go ahead\n", -9123);
    
    printf("printf    short unsigned int 4: %hu and go ahead\n", (short int)-9123);
    res = ft_printf("ft_printf short unsigned int 4: %hu and go ahead\n", -9123);

    printf("printf    short unsigned int 5: %hu and go ahead\n", (short int)-30700);
    res = ft_printf("ft_printf short unsigned int 5: %hu and go ahead\n", -30700);
   
    printf("printf    short short unsigned int 1: %3.2hhu and go ahead\n", (signed char)126);
    res = ft_printf("ft_printf short short unsigned int 1: %3.2hhu and go ahead\n", 126);
    
    printf("printf    short short unsigned int 2: %13.2hhu and go ahead\n", (signed char)-120);
    res = ft_printf("ft_printf short short unsigned int 2: %13.2hhu and go ahead\n", -120);
    
    printf("printf    short short unsigned int 3: %3.12hhu and go ahead\n", (signed char)-128);
    res = ft_printf("ft_printf short short unsigned int 3: %3.12hhu and go ahead\n", -128);
    
    printf("printf    short short unsigned int 4: %hhu and go ahead\n", (signed char)-9123);
    res = ft_printf("ft_printf short short unsigned int 4: %hhu and go ahead\n", -9123);
    
    printf("printf    short short unsigned int 5: %hhu and go ahead\n", (signed char)-30700);
    res = ft_printf("ft_printf short short unsigned int 5: %hhu and go ahead\n", -30700);
    
    printf("printf    short short unsigned int 6: %hhu and go ahead\n", (signed char)127);
    res = ft_printf("ft_printf short short unsigned int 4: %hhu and go ahead\n", 127);
 


    printf("\n-------------------------------------------------\n");
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

	printf("printf    hex 13: %20.13x and go ahead\n", 2147483647);
	res = ft_printf("ft_printf hex 13: %20.13x and go ahead\n", 2147483647);

	printf("printf    hex 14: %20.13x and go ahead\n", -2147483647);
	res = ft_printf("ft_printf hex 14: %20.13x and go ahead\n", -2147483647);

	printf("printf    hex 15: %5.15x and go ahead\n", -214748);
	res = ft_printf("ft_printf hex 15: %5.15x and go ahead\n", -214748);
 
    printf("printf    hex 16: %.4x and go ahead\n", -2147);
    res = ft_printf("ft_printf hex 16: %.4x and go ahead\n", -2147);
 
    printf("printf    hex 16: %4.4x and go ahead\n", -2147);
    res = ft_printf("ft_printf hex 16: %4.4x and go ahead\n", -2147);
    
    printf("printf    long hex 1: %2.13lx and go ahead\n", 4000000000);
    res = ft_printf("ft_printf long hex 1: %2.13lx and go ahead\n", 4000000000);
    
    printf("printf    long hex 2: %13.2lx and go ahead\n", 4300000000);
    res = ft_printf("ft_printf long hex 2: %13.2lx and go ahead\n", 4300000000);
    
    printf("printf    long hex 3: %3.12lx and go ahead\n", 9300000000);
    res = ft_printf("ft_printf long hex 3: %3.12lx and go ahead\n", 9300000000);
    
    printf("printf    long hex 4: %3.12lx and go ahead\n", -9030100100);
    res = ft_printf("ft_printf long hex 4: %3.12lx and go ahead\n", -9030100100);
    
    printf("printf    long hex 5: %13.2lx and go ahead\n", -4300000000);
    res = ft_printf("ft_printf long hex 5: %13.2lx and go ahead\n", -4300000000);
    
    printf("printf    long long hex 1: %3.2llx and go ahead\n", (long long)40100100100111222);
    res = ft_printf("ft_printf long long hex 1: %3.2llx and go ahead\n", 40100100100111222);
    
    printf("printf    long long hex 2: %13.2llx and go ahead\n", (long long)43100100100111222);
    res = ft_printf("ft_printf long long hex 2: %13.2llx and go ahead\n", 43100100100111222);
    
    printf("printf    long long hex 3: %3.12llx and go ahead\n", (long long)903100100100111222);
    res = ft_printf("ft_printf long long hex 3: %3.12llx and go ahead\n", 903100100100111222);
    
    printf("printf    long long hex 4: %3.2llx and go ahead\n", (long long)-40100100100111222);
    res = ft_printf("ft_printf long long hex 4: %3.2llx and go ahead\n", -40100100100111222);
    
    printf("printf    long long hex 5: %3.12llx and go ahead\n", (long long)-9030100100111222333);
    res = ft_printf("ft_printf long long hex 5: %3.12llx and go ahead\n", -9030100100111222333);
    
    printf("printf    short hex 1: %3.2hx and go ahead\n", (short int)30700);
    res = ft_printf("ft_printf short hex 1: %3.2hx and go ahead\n", 30700);
    
    printf("printf    short hex 2: %13.2hx and go ahead\n", (short int)-30700);
    res = ft_printf("ft_printf short hex 2: %13.2hx and go ahead\n", -30700);
    
    printf("printf    short hex 3: %3.12hx and go ahead\n", (short int)-9123);
    res = ft_printf("ft_printf short hex 3: %3.12hx and go ahead\n", -9123);
    
    printf("printf    short hex 4: %hx and go ahead\n", (short int)-9123);
    res = ft_printf("ft_printf short hex 4: %hx and go ahead\n", -9123);
    
    printf("printf    short hex 5: %hx and go ahead\n", (short int)-30700);
    res = ft_printf("ft_printf short hex 5: %hx and go ahead\n", -30700);
    
    printf("printf    short short hex 1: %3.2hhx and go ahead\n", (signed char)126);
    res = ft_printf("ft_printf short short hex 1: %3.2hhx and go ahead\n", 126);
    
    printf("printf    short short hex 2: %13.2hhx and go ahead\n", (signed char)-120);
    res = ft_printf("ft_printf short short hex 2: %13.2hhx and go ahead\n", -120);
    
    printf("printf    short short hex 3: %3.12hhx and go ahead\n", (signed char)-128);
    res = ft_printf("ft_printf short short hex 3: %3.12hhx and go ahead\n", -128);
    
    printf("printf    short short hex 4: %hhx and go ahead\n", (signed char)-9123);
    res = ft_printf("ft_printf short short hex 4: %hhx and go ahead\n", -9123);
    
    printf("printf    short short hex 5: %hhx and go ahead\n", (signed char)-30700);
    res = ft_printf("ft_printf short short hex 5: %hhx and go ahead\n", -30700);
    
    printf("printf    short short hex 6: %hhx and go ahead\n", (signed char)127);
    res = ft_printf("ft_printf short short hex 4: %hhx and go ahead\n", 127);


    int *int_ptr, *int_ptr2;
	char *char_ptr;
	char str_ptr[4] = "test";
	int i, j;
	char c;

	i = 21;
    j = -21;
	res = i;
	c = 'Z';
	int_ptr = &i;
    int_ptr2 = &j;
	char_ptr = &c;
	printf("printf    pointer int 1: %20p\n", int_ptr);
	res = ft_printf("ft_printf pointer int 1: %20p\n", int_ptr);
	
	printf("printf    pointer char 2: %20p\n", char_ptr);
	res = ft_printf("ft_printf pointer char 2: %20p\n", char_ptr);

	printf("printf    pointer char 3: %20p\n", str_ptr);
	res = ft_printf("ft_printf pointer char 3: %20p\n", str_ptr);
    
    printf("printf    pointer char 4: %10p\n", str_ptr);
    res = ft_printf("ft_printf pointer char 4: %10p\n", str_ptr);
    
    printf("printf    pointer char 5: %15p\n", int_ptr);
    res = ft_printf("ft_printf pointer char 5: %15p\n", int_ptr);
    
    printf("printf    pointer char 6: %10p\n", int_ptr);
    res = ft_printf("ft_printf pointer char 6: %10p\n", int_ptr);
    
    printf("printf    pointer char 7: %15p\n", int_ptr2);
    res = ft_printf("ft_printf pointer char 7: %15p\n", int_ptr2);
    
    printf("printf    pointer char 8: %17p\n", int_ptr2);
    res = ft_printf("ft_printf pointer char 8: %17p\n", int_ptr2);
    
    printf("printf    pointer char 9: %3p\n", char_ptr);
    res = ft_printf("ft_printf pointer char 9: %3p\n", char_ptr);
    
    printf("printf    pointer char 10: %30p\n", int_ptr);
    res = ft_printf("ft_printf pointer char 10: %30p\n", int_ptr);

	printf("\n----------------------------------------------------------------\n");
	printf("\nchar\n");
	printf("printf    char 1: %10c and go ahead\n", 'A');
   	res = ft_printf("ft_printf char 1: %10c and go ahead\n", 'A');
	
	printf("printf    char 2: %3c and go ahead\n", 'z');
	res = ft_printf("ft_printf char 2: %3c and go ahead\n", 'z');
    
    printf("printf    char 3: %3c and go ahead\n", 'A');
    res = ft_printf("ft_printf char 3: %3c and go ahead\n", 'A');
    
    printf("printf    char 3: %13c and go ahead\n", '!');
    res = ft_printf("ft_printf char 3: %13c and go ahead\n", '!');
    
    printf("printf    char 4: %1c and go ahead\n", 'A');
    res = ft_printf("ft_printf char 4: %1c and go ahead\n", 'A');
    
    printf("printf    char 5: %11c and go ahead\n", 'z');
    res = ft_printf("ft_printf char 5: %11c and go ahead\n", 'z');
    
    printf("printf    char 6: %c and go ahead\n", 'A');
    res = ft_printf("ft_printf char 6: %c and go ahead\n", 'A');
    
    printf("printf    char 7: %11c and go ahead\n", '!');
    res = ft_printf("ft_printf char 7: %11c and go ahead\n", '!');

	printf("\n----------------------------------------------------------------\n");
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
    
    printf("printf    string 6: %.5s and go ahead\n", "Test_string not be trash");
    res = ft_printf("ft_printf string 6: %.5s and go ahead\n", "Test_string not be trash");
    
    printf("printf    string 7: %5.10s and go ahead\n", "Test_string not be trash!!");
    res = ft_printf("ft_printf string 7: %5.10s and go ahead\n", "Test_string not be trash!!");
    
    printf("printf    string 8: %15.40s and go ahead\n", "Test_string not be trash at all!!");
    res = ft_printf("ft_printf string 8: %15.40s and go ahead\n", "Test_string not be trash at all!!");
    
    printf("printf    string 9: %30.5s and go ahead\n", "Test _strinG G G G G G");
    res = ft_printf("ft_printf string 9: %30.5s and go ahead\n", "Test _strinG G G G G G");

*/


    printf("\n----------------------------------------------------------------\n");
	printf("float, double\n");

    printf("printf    double 1: %.5f and go on\n", 771.83335);
	res = ft_printf("ft_printf double 1: %.5f and go on\n", 771.83335);

    printf("printf    double 2: %15.6f and go on\n", -783.234);
	res = ft_printf("ft_printf double 2: %15.6f and go on\n", -783.234);

	printf("printf    double 3: %.2f\n", 0.385);
	res = ft_printf("ft_printf double 3: %.2f\n", 0.385);

	printf("printf    double 4: %.6f\n", 11111.11111);	
	res = ft_printf("ft_printf double 4: %.6f\n", 11111.11111);
    
	printf("printf    double 5: %.3f and go on\n", 00.385);
	res = ft_printf("ft_printf double 5: %.3f and go on\n", 00.385);
	
	printf("printf    double 6: %3.6f\n", 24.00385);
	res = ft_printf("ft_printf double 6: %3.6f\n", 24.00385);

	printf("printf    double 7: %12.4f\n", 771.833);
	res = ft_printf("ft_printf double 7: %12.4f\n", 771.833);

	printf("printf    double 9: %.7f\n", -2.7182818);
	res = ft_printf("ft_printf double 9: %.7f\n", -2.7182818);

	printf("printf    double 10: %5.0f\n", 2.7182818);
	res = ft_printf("ft_printf double 10: %5.0f\n", 2.7182818);

	printf("printf    double 11: %5.1f\n", 2.7182818);
	res = ft_printf("ft_printf double 11: %5.1f\n", 2.7182818);

	printf("printf    double 12: %12.2f\n", -783.234);
	res = ft_printf("ft_printf double 12: %12.2f\n", -783.234);
 
    printf("printf    double 13: %12.4f\n", 783.234);
    res = ft_printf("ft_printf double 13: %12.4f\n", 783.234);
 
    printf("printf    double 14: %.0f\n", 783.234);
    res = ft_printf("ft_printf double 14: %.0f\n", 783.234);
    
    printf("printf    double 15: %.0f\n", 783.734);
    res = ft_printf("ft_printf double 15: %.0f\n", 783.734);

    printf("printf    double 16: %.18f\n", 783.73334);
    res = ft_printf("ft_printf double 16: %.18f\n", 783.73334);
    
    printf("printf    double 17: %.19f\n", -0.837333554);
    res = ft_printf("ft_printf double 17: %.19f\n", -0.837333554);
    
    printf("printf    double 18: %.19f\n", 783.73334);
    res = ft_printf("ft_printf double 18: %.19f\n", 783.73334);
    
    printf("printf    double 19: %f\n", -0.837333554);
    res = ft_printf("ft_printf double 19: %f\n", -0.837333554);
    
    printf("printf    double 20: %f\n", 783.73334);
    res = ft_printf("ft_printf double 20: %f\n", 783.73334);
    
    printf("printf    double 21: %30f\n", 783.73334);
    res = ft_printf("ft_printf double 21: %30f\n", 783.73334);
    
    printf("printf    double 22: %30f\n", -783.73334);
    res = ft_printf("ft_printf double 22: %30f\n", -783.73334);

    printf("printf    long double 1: %.5lf and go on\n", 771.83335);
    res = ft_printf("ft_printf long double 1: %.5lf and go on\n", 771.83335);
    
    printf("printf    long double 2: %9.3lf and go on\n", -783.234);
    res = ft_printf("ft_printf long double 2: %9.3lf and go on\n", -783.234);
    
    printf("printf    long double 3: %.2lf\n", 0.385);
    res = ft_printf("ft_printf long double 3: %.2lf\n", 0.385);
    
    printf("printf    long double 4: %.6lf\n", 11111.11111);
    res = ft_printf("ft_printf long double 4: %.6lf\n", 11111.11111);
    
    printf("printf    long double 5: %.3lf and go on\n", 00.385);
    res = ft_printf("ft_printf long double 5: %.3lf and go on\n", 00.385);
    
    printf("printf    long double 6: %3.6lf\n", 24.00385);
    res = ft_printf("ft_printf long double 6: %2.6lf\n", 24.00385);
    
    printf("printf    long double 7: %12.4lf\n", 771.833);
    res = ft_printf("ft_printf long double 7: %12.4lf\n", 771.833);
    
    printf("printf    long double 9: %.7lf\n", 2.7182818);
    res = ft_printf("ft_printf long double 9: %.7lf\n", 2.7182818);
    
    printf("printf    long double 10: %5.0lf\n", -2.7182818);
    res = ft_printf("ft_printf long double 10: %5.0lf\n", -2.7182818);
    
    printf("printf    long double 11: %5.1lf\n", 2.7182818);
    res = ft_printf("ft_printf long double 11: %5.1lf\n", 2.7182818);
    
    printf("printf    long double 12: %7.2lf\n", -783.234);
    res = ft_printf("ft_printf long double 12: %7.2lf\n", -783.234);
    
    printf("printf    long double 13: %12.4lf\n", 783.234);
    res = ft_printf("ft_printf long double 13: %12.4lf\n", 783.234);
    
    printf("printf    long double 14: %.0lf\n", 7800000000003.234);
    res = ft_printf("ft_printf long double 14: %.0lf\n", 7800000000003.234);
    
    printf("printf    Long double 1: %.5Lf and go on\n", (long double)7000000000071.83335);
    res = ft_printf("ft_printf Long double 1: %.5Lf and go on\n", 7000000000071.83335);
    
    printf("printf    Long double 2: %9.3Lf and go on\n", (long double)-7000000000083.234);
    res = ft_printf("ft_printf Long double 2: %9.3Lf and go on\n", -7000000000083.234);
    
    printf("printf    Long double 3: %.2Lf\n", (long double)0.0000000000385);
    res = ft_printf("ft_printf Long double 3: %.2Lf\n", 0.0000000000385);
    
    printf("printf    Long double 4: %.6Lf\n", (long double)111000000000011.11111);
    res = ft_printf("ft_printf Long double 4: %.6Lf\n", 111000000000011.11111);
    
    printf("printf    Long double 5: %.3Lf and go on\n", (long double)00.0000000000385);
    res = ft_printf("ft_printf Long double 5: %.3Lf and go on\n", 00.0000000000385);
    
    printf("printf    Long double 6: %3.6Lf\n", (long double)-240000000000.00385);
    res = ft_printf("ft_printf Long double 6: %2.6Lf\n", -240000000000.00385);
    
    printf("printf    Long double 7: %12.4Lf\n", (long double)7710000000000.833);
    res = ft_printf("ft_printf Long double 7: %12.4Lf\n", 7710000000000.833);
    
    printf("printf    Long double 9: %.7Lf\n", (long double)20000000000.7182818);
    res = ft_printf("ft_printf Long double 9: %.7Lf\n", 20000000000.7182818);
    
    printf("printf    Long double 10: %5.0Lf\n", (long double)2.00000000007182818);
    res = ft_printf("ft_printf Long double 10: %5.0Lf\n", 2.00000000007182818);
    
    printf("printf    Long double 11: %5.1Lf\n", (long double)20000000000.7182818);
    res = ft_printf("ft_printf Long double 11: %5.1Lf\n", 20000000000.7182818);
    
    printf("printf    Long double 12: %7.2Lf\n", (long double)-7830000000000.234);
    res = ft_printf("ft_printf Long double 12: %7.2Lf\n", -7830000000000.234);
    
    printf("printf    Long double 13: %12.4Lf\n", (long double)7830000000000.234);
    res = ft_printf("ft_printf Long double 13: %12.4Lf\n", 7830000000000.234);
    
    printf("printf    Long double 14: %.0Lf\n", (long double)7830000000000.234);
    res = ft_printf("ft_printf Long double 14: %.0Lf\n", 7830000000000.234);
    
	return (0);
}
