#include "printf.h"
#include <stdio.h>
int main(void)
{
    //miracle
/*
    ft_printf("16:%.7f\n", -875.000001);
    printf("16:%.7f\n", -875.000001);
    ft_printf("19:%.8f\n", -875.000001);
    printf("19:%.8f\n", -875.000001);
    ft_printf("%.9f\n", -875.000001);
*/
/*
    ft_printf("1:%.16f\n",  0.999999999999999900);
    printf("1:%.16f\n",  0.999999999999999900);
    ft_printf("2:%.16f\n",        1.025978548534310421);
    printf("2:%.16f\n",        1.025978548534310421);
    ft_printf("3:%.17f\n",        1.025978548534310421);
    printf("3:%.17f\n",        1.025978548534310421);
    ft_printf("4:%.18f\n",        0.125978548534310421);
    printf("4:%.18f\n",        0.125978548534310421);
*/
    ft_printf("5:%#.0f\n", -7.4);
    printf("5:%#.0f\n", -7.4);
    ft_printf("6:%05.0f\n", -7.3);
    printf("6:%05.0f\n", -7.3);
    ft_printf("7:%05.1f\n", -7.3);
    printf("7:%05.1f\n", -7.3);
    ft_printf("8:%-5.0f\n", 7.3);
    printf("8:%-5.0f\n", 7.3);
/*
    ft_printf("9:%-5.1f\n", 7.3);
    printf("9:%-5.1f\n", 7.3);
    ft_printf("10:%-5.3f\n", 7.3);
    printf("10:%-5.3f\n", 7.3);
    ft_printf("11:%-05.0f\n", 7.3);
    printf("11:%-05.0f\n", 7.3);
    ft_printf("12:%-05.1f\n", 7.3);
    printf("12:%-05.1f\n", 7.3);
    ft_printf("13:%-05.0f\n", -7.3);
    printf("13:%-05.0f\n", -7.3);
    ft_printf("14:%-05.1f\n", -7.3);
    printf("14:%-05.1f\n", -7.3);
    ft_printf("15:%0-5.0f\n", 7.3);
    printf("15:%0-5.0f\n", 7.3);
    ft_printf("16:%0-5.1f\n", 7.3);
    printf("16:%0-5.1f\n", 7.3);
    ft_printf("17:%0-5.0f\n", -7.3);
    printf("17:%0-5.0f\n", -7.3);
    ft_printf("18:%0-5.1f\n", -7.3);
    printf("18:%0-5.1f\n", -7.3);
*/
    
/*
    ft_printf("1:%.7f\n", 0.0000001);
    printf("1:%.7f\n", 0.0000001);
    ft_printf("7:%f\n", 23.00041);
    printf("7:%f\n", 23.00041);
    ft_printf("8:%f\n", 0.000039);
    printf("8:%f\n", 0.000039);
    ft_printf("2:%.7f\n", -0.0000001);
    printf("2:%.7f\n", -0.0000001);
    ft_printf("3:%.8f\n", 0.00000039);
    printf("3:%.8f\n", 0.00000039);
    ft_printf("4:this %.9f float\n", 1.5);
    printf("4:this %.9f float\n", 1.5);
    ft_printf("5:%.9f\n", 7.5);
    printf("5:%.9f\n", 7.5);
    ft_printf("6:%.9f\n", 1.0);
    printf("6:%.9f\n", 1.0);
    ft_printf("7:%.9f\n", -3.85);
    printf("7:%.9f\n", -3.85);
    ft_printf("8:%.9f\n", 573.924);
    printf("8:%.9f\n", 573.924);
    ft_printf("9:%.9f\n", -958.125);
    printf("9:%.9f\n", -958.125);
    ft_printf("10:%.9f\n", 23.00041);
    printf("10:%.9f\n", 23.00041);
    ft_printf("11:%.9f\n", 0.00000039);
    printf("11:%.9f\n", 0.00000039);
    ft_printf("12:%.9f\n", -7.00036);
    printf("12:%.9f\n", -7.00036);
    ft_printf("13:%.9f\n", -0.0000032);
    printf("13:%.9f\n", -0.0000032);
    ft_printf("14:%.9f\n", 0.00000001);
    printf("14:%.9f\n", 0.00000001);
    ft_printf("15:%.9f\n", -0.00000001);
    printf("15:%.9f\n", -0.00000001);
    ft_printf("16:%.9f\n", 9873.000001);
    printf("16:%.9f\n", 9873.000001);
    ft_printf("17:%.9f\n", -875.000001);
    printf("17:%.9f\n", -875.000001);
    ft_printf("18:%.9f\n", 999.99999999);
    printf("18:%.9f\n", 999.99999999);
    ft_printf("19:%.9f\n", -99.99999999);
    printf("19:%.9f\n", -99.99999999);
    ft_printf("20:%.9f\n", 0.999999);
    printf("20:%.9f\n", 0.999999);
    ft_printf("21:%.9f\n", -0.999999);
	printf("21:%.9f\n", -0.999999);

    ft_printf("%.9f", 23.375094499);
    ft_printf("%.9f", -985.765426499);
    ft_printf("%.9f", 0.0894255);
    ft_printf("%.9f", -56.2012685);
    ft_printf("%.9f", 43.4399999);
    ft_printf("%.9f", -5.0299999);
    ft_printf("%.9f", 43.43999949);
    ft_printf("%.9f", -5.02999949);
    ft_printf("%.9f", 1.99999949);
    ft_printf("%.9f", -0.99999949);
    ft_printf("%.9f", 3.9999999);

    // older tests

    ft_printf("1:this %f float\n", 1.5);
    printf("1:this %f float\n", 1.5);
    ft_printf("2:%f\n", 7.5);
    printf("2:%f\n", 7.5);
    ft_printf("3:%f\n", 1.0);
    printf("3:%f\n", 1.0);
    ft_printf("4:%f\n", -3.85);
    printf("4:%f\n", -3.85);
    ft_printf("5:%f\n", 573.924);
    printf("5:%f\n", 573.924);
    ft_printf("6:%f\n", -958.125);
    printf("6:%f\n", -958.125);
  	
  
    ft_printf("1:%f\n", 1.0);
    printf("1:%f\n", 1.0);

	ft_printf("2:%f\n", -875.000001);
    printf("2:%f\n", -875.000001);
   

    ft_printf("3:%f\n", 3.9999999);
    printf("3:%f\n", 3.9999999);
    ft_printf("4:%f\n", -5.9999999);
    printf("4:%f\n", -5.9999999);
    ft_printf("5:%.1f\n", 1.0);
    printf("5:%.1f\n", 1.0);
    ft_printf("6:%.1f\n", 23.00041);
    printf("6:%.1f\n", 23.00041);
    ft_printf("7:%.1f\n", 0.000039);
    printf("7:%.1f\n", 0.000039);
    ft_printf("8:%.1f\n", -7.00036);
    printf("8:%.1f\n", -7.00036);
    ft_printf("9:%.1f\n", -0.00032);
    printf("9:%.1f\n", -0.00032);
    ft_printf("10:%.3f\n", 1.0);
    printf("10:%.3f\n", 1.0);
    ft_printf("11:%.3f\n", 23.00041);
    printf("11:%.3f\n", 23.00041);
    ft_printf("12:%.3f\n", 0.000039);
    printf("12:%.3f\n", 0.000039);
    ft_printf("13:%.3f\n", -7.00036);
    printf("13:%.3f\n", -7.00036);
    ft_printf("14:%.3f\n", -0.00032);
    printf("14:%.3f\n", -0.00032);
    ft_printf("15:%.7f\n", 1.0);
    printf("15:%.7f\n", 1.0);
    ft_printf("16:%.7f\n", -875.000001);
    printf("16:%.7f\n", -875.000001);

    ft_printf("17:%.8f\n", 1.0);
    printf("17:%.8f\n", 1.0);
    ft_printf("18:%.8f\n", 9873.000001);
    printf("18:%.8f\n", 9873.000001);
    ft_printf("19:%.8f\n", -875.000001);
    printf("19:%.8f\n", -875.000001);
    ft_printf("20:%.8f\n", 999.9999999);
    printf("20:%.8f\n", 999.9999999);
    ft_printf("21:%.8f\n", -99.99999999);
    printf("21:%.8f\n", -99.99999999);
    ft_printf("22:%.8f\n", 0.999999);
    printf("22:%.8f\n", 0.999999);
    ft_printf("23:%.8f\n", -0.999999);
    printf("23:%.8f\n", -0.999999);
    ft_printf("24:%.8f\n", 23.375094499);
    printf("24:%.8f\n", 23.375094499);
    ft_printf("25:%.8f\n", -985.765426499);
    printf("25:%.8f\n", -985.765426499);
 
*/

/*
    ft_printf("1:this %#X number\n", 17);
    printf("1:this %#X number\n", 17);
    ft_printf("2:this %#X number\n", 0);
    printf("2:this %#X number\n", 0);
    ft_printf("3:%#X\n", 3);
    printf("3:%#X\n", 3);
    ft_printf("4:%#X\n", 4294967295u);
    printf("4:%#X\n", 4294967295u);
    ft_printf("5:%#7X\n", 33);
    printf("5:%#7X\n", 33);
    ft_printf("1:%#.0x\n", 0);
    printf("1:%#.0x\n", 0);
    ft_printf("2:%#.x\n", 0);
    printf("2:%#.x\n", 0);
	ft_printf("3:%.0x\n", 0);
	printf("3:%.0x\n", 0);
	ft_printf("4:%.x\n", 0);
	printf("4:%.x\n", 0);   
*/
 
/*  ft_printf("1:%#8.5x\n", 0);
	printf("1:%#8.5x\n", 0);
    ft_printf("2:%#-8.5x\n", 34);
	printf("2:%#-8.5x\n", 34);
  	ft_printf("3:%#-8.5x\n", 0);
	printf("3:%#-8.5x\n", 0);
    ft_printf("4:%#-2.7x\n", 3267);
	printf("4:%#-2.7x\n", 3267);
    ft_printf("5:%#08.5x\n", 0);
	printf("5:%#08.5x\n", 0);
    
	ft_printf("6_1:%#08.3x\n", 8375);
	printf("6_1:%#08.3x\n", 8375);
    ft_printf("6_2:%#05x\n", 43);
	printf("6_2:%#05x\n", 43);
	
	ft_printf("7:%#0-8.5x\n", 34);
	printf("7:%#0-8.5x\n", 34);
    ft_printf("8:%#0-8.5x\n", 0);
    printf("8:%#0-8.5x\n", 0);
	ft_printf("9:%#0-2.7x\n", 3267);
	printf("9:%#0-2.7x\n", 3267);
    
	ft_printf("0:%#-7x\n", 33);
	printf("0:%#-7x\n", 33);
  	ft_printf("1:%#7x\n", 33);
	printf("1:%#7x\n", 33);
    ft_printf("2:%#5x\n", 52625);
    printf("2:%#5x\n", 52625);
    ft_printf("3:%#-5x\n", 52625);
    printf("3:%#-5x\n", 52625);
    ft_printf("4:%#.5x\n", 21);
    printf("4:%#.5x\n", 21);
    ft_printf("5:%#.3x\n", 0);
    printf("5:%#.3x\n", 0);
    ft_printf("6:%#05x\n", 43);
    printf("6:%#05x\n", 43);
    ft_printf("7:%#8.5x\n", 34);
    printf("7:%#8.5x\n", 34);
    ft_printf("8:%#8.3x\n", 8375);
    printf("8:%#8.3x\n", 8375);
    ft_printf("9:%#2.7x\n", 3267);
    printf("9:%#2.7x\n", 3267);
*/
    
/*  ft_printf("6:%.0o\n", 0);
    printf("6:%.0o\n", 0);
    ft_printf("7:%.o\n", 0);
    printf("7:%.o\n", 0);
   
   	ft_printf("8:%5.0o\n", 0);
    printf("8:%5.0o\n", 0);
   
   	ft_printf("9:%5.o\n", 0);
    printf("9:%5.o\n", 0);
    ft_printf("10:%-5.0o\n", 0);
    printf("10:%-5.0o\n", 0);
    ft_printf("11:%-5.o\n", 0);
    printf("11:%-5.o\n", 0);

    ft_printf("ft1:this %#o number\n", 0);
    printf("pt1:this %#o number\n", 0);
    ft_printf("ft2:%#3o\n", 0);
    printf("pt2:%#3o\n", 0);
    ft_printf("ft3:%#-3o\n", 0);
    printf("ft3:%#-3o\n", 0);
    
	ft_printf("ft12:%#.0o\n", 0);
    printf("pt12:%#.0o\n", 0);
    ft_printf("ft13:%#.o\n", 0);
    printf("pt13:%#.o\n", 0);
    ft_printf("14:%#5.0o\n", 0);
    printf("14:%#5.0o\n", 0);
    ft_printf("15:%#5.o\n", 0);
    printf("15:%#5.o\n", 0);
    ft_printf("16:%#-5.0o\n", 0);
    printf("16:%#-5.0o\n", 0);
    ft_printf("17:%#-5.o\n", 0);
    printf("17:%#-5.o\n", 0);
*/
/*
    ft_printf("1:%#8.5o\n", 34);
    printf("1:%#8.5o\n", 34);
    ft_printf("2:%#-8.5o\n", 34);
    printf("2:%#-8.5o\n", 34);
    ft_printf("3:%#-2.7o\n", 3267);
    printf("3:%#-2.7o\n", 3267);
    ft_printf("4:%#08.5o\n", 34);
    printf("4:%#08.5o\n", 34);
    ft_printf("5:%#0-8.5o\n", 34);
    printf("5:%#0-8.5o\n", 34);
    ft_printf("6:%#0-2.7o\n", 3267);
    printf("6:%#0-2.7o\n", 3267);
*/
    
/*
// 	ft_printf("ft:this %#o number\n", 0);
//	printf("pt:this %#o number\n", 0);
//	ft_printf("ft:%#3o\n", 0);
//	printf("pt:%#3o\n", 0);
	ft_printf("ft:%#-7o\n", 33);
	printf("pt:%#-7o\n", 33);
	ft_printf("ft:%#.5o\n", 21);
	printf("pt:%#.5o\n", 21);
	ft_printf("ft:%#.3o\n", 0);
	printf("pt:%#.3o\n", 0);

    ft_printf("this %#o number\n", 17);
    printf("this %#o number\n", 17);
    ft_printf("%#o\n", 3);
    printf("%#o\n", 3);
    ft_printf("%#o\n", 4294967295u);
    printf("%#o\n", 4294967295u);
    ft_printf("%#7o\n", 33);
    printf("%#7o\n", 33);
	ft_printf("%#3o\n", 0);
  	printf("%#3o\n", 0);
*/    
    
 /*   ft_printf("%6o\n", 52625);
    printf("%6o\n", 52625);
    ft_printf("%.5o\n", 5263);
    printf("%.5o\n", 5263);
    ft_printf("%07o\n", 698334);
    printf("%07o\n", 698334);
    ft_printf("%8.3o\n", 8375);
    printf("%8.3o\n", 8375);
    ft_printf("%08.3o\n", 8375);
    printf("%08.3o\n", 8375);
	ft_printf("%037lo\n", 22337203685477ul);
	printf("%037lo\n", 22337203685477ul);
	ft_printf("%37llo\n", 522337203685470ull);
	printf("%37llo\n", 522337203685470ull);   
*/

/*
 	ft_printf("ft1:%.0d\n", 0);
    printf("pt1:%.0d\n", 0);
    ft_printf("ft2:%.d\n", 0);
    printf("pt2:%.d\n", 0);
    ft_printf("ft3:%5.0d\n", 0);
    printf("pt3:%5.0d\n", 0);
    ft_printf("ft4:%5.d\n", 0);
    printf("pt4:%5.d\n", 0);
    ft_printf("ft5:%-5.0d\n", 0);
    printf("pt5:%-5.0d\n", 0);
    ft_printf("ft6:%-5.d\n", 0);
    printf("pt6:%-5.d\n", 0);
    ft_printf("ft7:%+.0d\n", 0);
    printf("pt7:%+.0d\n", 0);
    ft_printf("ft8:%+.d\n", 0);
    printf("pt8:%+.d\n", 0);
	ft_printf("ft9:%+5.0d\n", 0);
    printf("pt9:%+5.0d\n", 0);
    ft_printf("ft10:%+5.d\n", 0);
    printf("pt10:%+5.d\n", 0);
	ft_printf("ft11:%+-5.0d\n", 0);
	printf("pt11:%+-5.0d\n", 0);
	ft_printf("ft12:%+-5.d\n", 0);
	printf("pt12:%+-5.d\n", 0);
 */  
    
/*
    ft_printf("% 0+-8.5d\n", 34);
    printf("% 0+-8.5d\n", 34);
    ft_printf("% 0+-10.5d\n", -216);
    printf("% 0+-10.5d\n", -216);
    ft_printf("% 0+-8.5d\n", 0);
    printf("% 0+-8.5d\n", 0);
    ft_printf("% 0+-8.3d\n", 8375);
    printf("% 0+-8.3d\n", 8375);
    ft_printf("% 0+-8.3d\n", -8473);
    printf("% 0+-8.3d\n", -8473);
    ft_printf("% 0+-3.7d\n", 3267);
    printf("% 0+-3.7d\n", 3267);
    ft_printf("% 0+-3.7d\n", -2375);
    printf("% 0+-3.7d\n", -2375);
    ft_printf("% 0+-3.3d\n", 6983);
    printf("% 0+-3.3d\n", 6983);
    ft_printf("% 0+-3.3d\n", -8462);
    printf("% 0+-3.3d\n", -8462);    
    

    ft_printf("%037ld\n", 22337203685477l);
    printf("%037ld\n", 22337203685477l);
    ft_printf("%.37ld\n", -22337203685477l);
    printf("%.37ld\n", -22337203685477l);
    ft_printf("%37lld\n", 522337203685470ll);
    printf("%37lld\n", 522337203685470ll);
    ft_printf("%-37lld\n", -522337203685470ll);
    printf("%-37lld\n", -522337203685470ll);
    ft_printf("%+ld\n", 22337203685477l);
    printf("%+ld\n", 22337203685477l);

	ft_printf("% -8.5d\n", 34);
    printf("% -8.5d\n", 34);
    ft_printf("% -8.5d\n", 0);
    printf("% -8.5d\n", 0);

    ft_printf("0:% -7d\n", -14);
    printf("0:% -7d\n", -14);
    ft_printf("1:% -5d\n", -2562);
    printf("1:% -5d\n", -2562);
    
	ft_printf("2!:% 07d\n", -54);
    printf("2!:% 07d\n", -54);
    ft_printf("3!:% 04d\n", -532);
    printf("3!:% 04d\n", -532);
    ft_printf("4!:% +05d\n", 432);
    printf("4!:% +05d\n", 432);
    ft_printf("5!:% +04d\n", 0);
    printf("5!:% +04d\n", 0);
   
   	ft_printf("6:% 8.5d\n", 34);
    printf("6:% 8.5d\n", 34);
    ft_printf("11:% 08.5d\n", 34);
    printf("11:% 08.5d\n", 34);
    ft_printf("13:% 08.5d\n", 0);
    printf("13:% 08.5d\n", 0);
    
	ft_printf("14!:% 08.3d\n", 8375);
    printf("14!:% 08.3d\n", 8375);
    ft_printf("15!:% 08.3d\n", -8473);
    printf("15!:% 08.3d\n", -8473);
 	
	ft_printf("8!:% -8.5d\n", 0);
 	printf("8!:% -8.5d\n", 0);

    ft_printf("2:% -7d\n", 33);
    printf("2:% -7d\n", 33);
    ft_printf("3:% -3d\n", 0);
    printf("3:% -3d\n", 0);
    ft_printf("4!:% 05d\n", 43);
    printf("4!:% 05d\n", 43);
    ft_printf("5!:% 03d\n", 0);
    printf("5!:% 03d\n", 0);
    ft_printf("7!:% -8.5d\n", 34);
    printf("7!:% -8.5d\n", 34);
    ft_printf("8:% -8.3d\n", -8473);
    printf("8:% -8.3d\n", -8473);
    ft_printf("9:% +-8.3d\n", 8375);
    printf("9:% +-8.3d\n", 8375);
    ft_printf("10:% +-8.3d\n", -8473);
    printf("10:% +-8.3d\n", -8473);
    
    ft_printf("12:% 010.5d\n", -216);
    printf("12:% 010.5d\n", -216);
    
    ft_printf("16:% 03.7d\n", 3267);
    printf("16:% 03.7d\n", 3267);
    ft_printf("17:% 03.7d\n", -2375);
    printf("17:% 03.7d\n", -2375);
    ft_printf("18:% 03.3d\n", 6983);
    printf("18:% 03.3d\n", 6983);
    ft_printf("19:% 03.3d\n", -8462);
    printf("19:% 03.3d\n", -8462);

    ft_printf("10:%hd\n", (short)-385);
    printf("10:%hd\n", (short)-385);
    ft_printf("11:%hd\n", -8875);
    printf("11:%hd\n", -8875);

    ft_printf("1:% .5d\n", 2);
    printf("1:% .5d\n", 2);
    ft_printf("2:% .3d\n", 0);
    printf("2:% .3d\n", 0);
    ft_printf("3:% +.7d\n", 234);
    printf("3:% +.7d\n", 234);
    
    
    ft_printf("6:% 3.7d\n", 3267);
    printf("6:% 3.7d\n", 3267);
 
    ft_printf("9:% -3.7d\n", 3267);
    printf("9:% -3.7d\n", 3267);
 
    ft_printf("ft:%0+8.5d\n", 34);
	printf("pt:%0+8.5d\n", 34);
    ft_printf("ft:%0+10.5d\n", -216);
	printf("pt:%0+10.5d\n", -216);
    ft_printf("ft:%0+8.5d\n", 0);
    printf("pt:%0+8.5d\n", 0);
    ft_printf("ft:%0+8.3d\n", 8375);
    printf("pt:%0+8.3d\n", 8375);
    ft_printf("ft:%0+8.3d\n", -8473);
    printf("pt:%0+8.3d\n", -8473);
    ft_printf("ft:%0+3.7d\n", 3267);
    printf("pt:%0+3.7d\n", 3267);
    ft_printf("ft:%0+3.7d\n", -2375);
    printf("pt:%0+3.7d\n", -2375);
    ft_printf("ft:%0+3.3d\n", 6983);
	printf("pt:%0+3.3d\n", 6983);
    ft_printf("ft:%0+3.3d\n", -8462);
    printf("pt:%0+3.3d\n", -8462);


	printf("ignored flags\n");

	ft_printf("ft:%0+-8.5d\n", 34);
    printf("pt:%0+-8.5d\n", 34);
    ft_printf("ft:%0+-10.5d\n", -216);
    printf("pt:%0+-10.5d\n", -216);
    ft_printf("ft:%0+-8.5d\n", 0);
    printf("pt:%0+-8.5d\n", 0);
    ft_printf("ft:%0+-8.3d\n", 8375);
    printf("pt:%0+-8.3d\n", 8375);
    ft_printf("ft:%0+-8.3d\n", -8473);
    printf("pt:%0+-8.3d\n", -8473);
    ft_printf("ft:%0+-3.7d\n", 3267);
    printf("pt:%0+-3.7d\n", 3267);
    ft_printf("ft:%0+-3.7d\n", -2375);
    printf("pt:%0+-3.7d\n", -2375);
    ft_printf("ft:%0+-3.3d\n", 6983);
    printf("pt:%0+-3.3d\n", 6983);
    ft_printf("ft:%0+-3.3d\n", -8462);
    printf("pt:%0+-3.3d\n", -8462);

	printf("---------------------\n");

    ft_printf("ft:%08.5d\n", 34);
    printf("pt:%08.5d\n", 34);
    ft_printf("ft:%010.5d\n", -216);
    printf("pt:%010.5d\n", -216);
    ft_printf("ft:%08.5d\n", 0);
    printf("pt:%08.5d\n", 0);
    ft_printf("ft:%08.3d\n", 8375);
    printf("pt:%08.3d\n", 8375);
    ft_printf("ft:%08.3d\n", -8473);
    printf("pt:%08.3d\n", -8473);

    ft_printf("ft:%-8.5d\n", 34);
    printf("pt:%-8.5d\n", 34);
    ft_printf("ft:%-10.5d\n", -216);
    printf("pt:%-10.5d\n", -216);
    ft_printf("ft:%-8.5d\n", 0);
    printf("pt:%-8.5d\n", 0);
    ft_printf("ft:%-3.7d\n", 3267);
    printf("pt:%-3.7d\n", 3267);
    ft_printf("ft:%-3.7d\n", -2375);
	printf("pt:%-3.7d\n", -2375);
    ft_printf("ft:%8.5d\n", 34);
    printf("pt:%8.5d\n", 34);
    ft_printf("ft:%10.5d\n", -216);
    printf("pt:%10.5d\n", -216);
    ft_printf("ft:%8.5d\n", 0);
    printf("pt:%8.5d\n", 0);
    ft_printf("ft:%07d\n", -54);
	printf("pt:%07d\n", -54);
	ft_printf("ft:%+07d\n", 54);
	printf("pt:%+07d\n", 54);
	ft_printf("ft1:%-7d\n", 33);
	printf("pt1:%-7d\n", 33);
	ft_printf("ft2:%-5d\n", -2562);
	printf("pt2:%-5d\n", -2562);
	ft_printf("ft3:%+5d\n", 35);
	printf("pt3:%+5d\n", 35);
	ft_printf("ft4:%+7d\n", 0);
	printf("pt4:%+7d\n", 0);
	ft_printf("ft5:%+24d\n", 2147483647);
	printf("pt5:%+24d\n", 2147483647);
	ft_printf("ft6:% 7d\n", 33);
	printf("pt6:% 7d\n", 33);
	printf("pt1:this %d number\n", 0);
	ft_printf("ft1:this %d number\n", 0);
	printf("pt2:this %i number\n", 0);
	ft_printf("ft2:this %i number\n", 0);
	printf("pt3:%d\n", 0);
	ft_printf("ft3:%d\n", 0);
	printf("pt4:%3d\n", 0);
	ft_printf("ft4:%3d\n", 0);
	printf("pt5:%-3d\n", 0);
	ft_printf("ft5:%-3d\n", 0);
	printf("pt6:%-7d\n", -14);
	ft_printf("ft6:%-7d\n", -14);
*/
/*
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

	printf("test 1: %-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("test 1: %-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	printf("\n");
	printf("test 2: %-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("test 2: %-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	printf("\n");
	printf("test 3: %-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("test 3: %-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);

	ft_printf("ft_printf:%%\n");
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
