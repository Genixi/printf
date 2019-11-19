#include "printf.h"
#include <stdio.h>
int main(void)
{
	static char	a01;
	static unsigned char a02;
	static short a03;
	static unsigned short a04;
	static int a05;
	static unsigned int a06;
	static long a07;
	static unsigned long a08;
	static long long a09;
	static unsigned long long a10;
	static char *a11;
	static void *a12;

	printf("%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	printf("%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	printf("%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);

/*	ft_printf("ft_printf:%%\n");
 	printf("printf   :%%\n");
	ft_printf("ft_printf:%5%\n");
    printf("printf   :%5%\n");
	ft_printf("ft_printf:%-5%\n");
    printf("printf   :%-5%\n");
    ft_printf("ft_printf:%05%\n");
    printf("printf   :%05%\n");
    ft_printf("ft_printf:%-05%\n");
    printf("printf   :%-05%\n");

	ft_printf("ft_printf:hello, %s.\n", NULL);
    printf("printf   :hello, %s.\n", NULL);
    ft_printf("ft_printf:%s\n", NULL);
  	printf("printf   :%s\n", NULL);
    ft_printf("ft_printf:%32s\n", NULL);
  	printf("printf   :%32s\n", NULL);
    ft_printf("ft_printf:%2s\n", NULL);
	printf("printf   :%2s\n", NULL);
    ft_printf("ft_printf:%-32s\n", NULL);
	printf("printf   :%-32s\n", NULL);
    ft_printf("ft_printf:%-16s\n", NULL);
  	printf("printf   :%-16s\n", NULL);
    ft_printf("ft_printf:%-3s\n", NULL);
	printf("printf   :%-3s\n", NULL);
	ft_printf("ft_printf:%.9s\n", NULL);
    printf("printf   :%.9s\n", NULL);
    ft_printf("ft_printf:%.3s\n", NULL);
	printf("printf   :%.3s\n", NULL);

	ft_printf("ft_printf_1:%32s\n", "abc");
	printf("printf_1   :%32s\n", "abc");
	ft_printf("ft_printf_2:%16s\n", "nark nark");
	printf("printf_2   :%16s\n", "nark nark");
	ft_printf("ft_printf_3:%-32s\n", "abc");
	printf("printf_3   :%-32s\n", "abc");
	ft_printf("ft_printf_4:%-16s\n", "nark nark");
	printf("printf_4   :%-16s\n", "nark nark");
	ft_printf("ft_printf_5%.0s\n", "hello");
	printf("printf_5   %.0s\n", "hello");   
	ft_printf("ft_printf_6:%7.5s\n", "bombastic");
	printf("printf_6   :%7.5s\n", "bombastic");
	ft_printf("ft_printf_7:%-7.5s\n", "tubular");
	printf("printf_7   :%-7.5s\n", "tubular");
*/	
	return (0);
}
