#include "printf.h"
#include <stdio.h>

int main() {
    int res;
    int i;
    char c;
    char str[] = "test";

    i = 1;
    c = 'A';
    res = ft_printf("Hello, %d World!\n", i);
    res = ft_printf("Hello, %c World!\n", c);
	res = ft_printf("Hello, %s World!\n", str);
    printf("result: %d\n", res);
    return 0;
}