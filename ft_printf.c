#include "printf.h"
#include "libft.h"
#include <unistd.h>

int ft_pars_format(char *str, va_list ap)
{
	int d;
	char c;
	char *s;

	if (*str == 'd' || *str == 'i')
	{
		d = va_arg(ap, int);
		ft_putnbr(d);
	}
	else if (*str == 'c')
	{
		c = va_arg(ap, char);
		write(1, &c, 1);
	}
	else if (*str == 's' || *str == 'S')
	{
		s = va_arg(ap, char*);
		ft_putstr(s);
	}
    return (0);
}

int ft_printf(const char *restrict format, ...)
{
    char *str;
    int res;

    va_list ap;
    va_start(ap, format);
    res = 0;
    str = (char*)format;
    while (*str)
    {
        if (*str == '%')
        {
            str++;
            res = ft_pars_format(str, ap);
        }
        else
            write(1, str, 1);
        str++;
    }

    va_end(ap);
    return (res);
}
